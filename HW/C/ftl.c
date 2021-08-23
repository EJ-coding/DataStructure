
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include "blockmap.h"
#include <time.h>

void ftl_read(int lsn, char *sectorbuf);
void ftl_write(int lsn, char *sectorbuf);
void ftl_print();
int free_block_pbn();
void update_data(int,int,int);

extern FILE *flashfp;
extern int dd_read(int ppn, char *pagebuf);
extern int dd_write(int ppn, char *pagebuf);
extern int dd_erase(int pbn);

char check_free[BLOCKS_PER_DEVICE];
_Bool check = 0;// check가 0이면  초기 ftl_open 호출

//block mapping table entry
typedef struct
{
     int pbn;
     int offset ;
} BlockTableEntry;

//block mapping table
typedef struct
{
     BlockTableEntry entry[DATABLKS_PER_DEVICE];
} BlockTable;

typedef struct
{
     int lsn;
   
} SpareAreaData;



BlockTable blocktable;
SpareAreaData spare_area_data[PAGES_PER_BLOCK * BLOCKS_PER_DEVICE];



void ftl_open()
{
    int i;
    
    flashfp = fopen("flashmemory", "w+b");
    
    if(flashfp == NULL)
    {
        printf("file open error for flashmemory\n");
        exit(1);
    }
     
    for(i = 0; i < DATABLKS_PER_DEVICE;i++)
    {
        blocktable.entry[i].pbn = -1;//pbn 초기화 모두 -1
        blocktable.entry[i].offset = 0;
    }
     
    for(i =0 ; i< BLOCKS_PER_DEVICE; i++)
    {
        check_free[i] = '1';
    }
     
    for(i=0; i<PAGES_PER_BLOCK * BLOCKS_PER_DEVICE; i++)
    {
        spare_area_data[i].lsn = -1;//lsn : -1로 초기화
    }

    return;
}

void ftl_read(int lsn, char *sectorbuf)
{
    // check가 0이면  초기 ftl_open 호출
    if(check == 0)
    {
        ftl_open();
        check = 1;
    }
    if(lsn/PAGES_PER_BLOCK > DATABLKS_PER_DEVICE || lsn < 0)
    {
        printf("error for lbn\n");
        return ;
    }
   
    int ppn;//physical page number
    int i;
    int file_lsn; //처음 읽어온 데이터(filesystem)의 lsn
    char pagebuffer[PAGE_SIZE]; //page읽어오는 buffer
    
    memset(sectorbuf,0xFF,SECTOR_SIZE); //pagebuffer 초기화
    //block rear -->read
    for(i=blocktable.entry[lsn/PAGES_PER_BLOCK].offset - 1; i>=0; i--)
    {
        //physical page number 구하기
        ppn = blocktable.entry[lsn/PAGES_PER_BLOCK].pbn * PAGES_PER_BLOCK + i;
        //read file
        dd_read(ppn,pagebuffer);
        //file system's lsn으로 가져온다.
        sscanf(pagebuffer+SECTOR_SIZE,"%d",&file_lsn);
        //읽어야할 데이터이면 찾기를 종료한다.
        if(file_lsn == lsn)
            break;
    }
    //sector buffer에 데이터 저장
    strncpy(sectorbuf,pagebuffer,SECTOR_SIZE);
  
    return;
}

void ftl_write(int lsn, char *sectorbuf)
{
    // check가 0이면  초기 ftl_open 호출
    if(check == 0)
    {
        check = 1;
        ftl_open();
    }
    int new_lbn;
    int ppn_tmp, prev_block;

    new_lbn =  lsn/PAGES_PER_BLOCK;
    if(new_lbn > DATABLKS_PER_DEVICE || lsn < 0)
    {
        printf("error for lbn\n");
        return ;
    }
    
    char pagebuf_tmp[PAGE_SIZE];
    memset(pagebuf_tmp,0xFF,PAGE_SIZE);
    //데이터가 없을 경우
    if(blocktable.entry[new_lbn].offset < PAGES_PER_BLOCK)
    {
        //초기상태일 때
        if(blocktable.entry[new_lbn].pbn == -1)
        {
            blocktable.entry[new_lbn].pbn = free_block_pbn();
            check_free[blocktable.entry[new_lbn].pbn] = '0';
        }
    }else //데이터에 차이가 날때
    {
        //이전 physical block number
        prev_block = blocktable.entry[new_lbn].pbn;
        //free block 할당
        blocktable.entry[new_lbn].pbn = free_block_pbn();
        blocktable.entry[new_lbn].offset = 0; //initialize offset
        update_data(blocktable.entry[new_lbn].pbn,prev_block,lsn); //update
        dd_erase(prev_block); //erase previous block
        //check_free : 비었으면 1 채웠으면 0
        check_free[prev_block] = '1';
        check_free[blocktable.entry[new_lbn].pbn] = '0';
    }
    
    ppn_tmp = blocktable.entry[new_lbn].pbn * PAGES_PER_BLOCK + blocktable.entry[new_lbn].offset; //ppn계산
    //page buffer에 sector buffer저장
    sprintf(pagebuf_tmp,"%s",sectorbuf);
    sprintf(pagebuf_tmp+SECTOR_SIZE,"%d",lsn);
    // lsn값을 spare에 복사
    spare_area_data[ppn_tmp].lsn = lsn;
    
    dd_write(ppn_tmp,pagebuf_tmp);
    blocktable.entry[new_lbn].offset++;
    return;
}



void ftl_print()
{
    int i;
     
    printf("Block Mapping Table: \n");
    for(i = blocktable.entry[i].pbn*PAGES_PER_BLOCK; i <(blocktable.entry[i].pbn+1)*PAGES_PER_BLOCK; i++)
    {
        printf("lsn:");
        printf("%d", spare_area_data[i].lsn);
    }
    for(i = 0; i < DATABLKS_PER_DEVICE; i++)
    {
        if(blocktable.entry[i].pbn >= 0)
        {
            printf("\n pbn : %d\n",  blocktable.entry[i].pbn);
        }
    }
    printf("free block's pbn = %d",free_block_pbn());
 
}
//ftl_write할때 두가지경우생각
void update_data(int prev_block_num, int curl_block_num,int lsn)
{
    int i,ppn,file_lsn;
    char buf[PAGE_SIZE];
    //buffer 초기화
    memset(buf,0xFF,PAGE_SIZE);
    //lsn이 중복되는지 확인
    int check[PAGES_PER_BLOCK]={0,};
     
    for(i=PAGES_PER_BLOCK-1; i>=0; i--)
    {
        ppn = prev_block_num * PAGES_PER_BLOCK + i;
        //이전 버퍼에 읽어온다
        dd_read(ppn,buf);
        sscanf(buf+SECTOR_SIZE,"%d",&file_lsn);
        //prev lsn = -1
        spare_area_data[ppn].lsn = -1;
         
        //file_lsn이 입력받은 lsn과 다를경우, 새로운 블록에 쓴다.
        if(file_lsn != lsn && check[file_lsn%PAGES_PER_BLOCK] != -1)
        {
            int cur_ppn = curl_block_num * PAGES_PER_BLOCK + blocktable.entry[lsn/PAGES_PER_BLOCK].offset;
            dd_write(cur_ppn,buf); //유효한 데이터를 현재 블럭에 쓴다
            //현재 lsn 설정
            spare_area_data[cur_ppn].lsn = file_lsn;
            blocktable.entry[lsn/PAGES_PER_BLOCK].offset++;
        }
          
        check[file_lsn%PAGES_PER_BLOCK] = -1; //중복 -1
    }
}

int free_block_pbn()
{
    int i=0;
     //free block을 찾는다 1이면 free block
    while(1)
    {
        if(check_free[i] == '1')
            break;
        else
            i++;
    }
     
    return i;
}
