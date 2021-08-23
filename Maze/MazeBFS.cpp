#include "Location2D.h"
#include <queue>
#include <stdio.h>
using namespace std;

const int MAZE_SIZE = 6;//미로 맵 크기 고정
char map[MAZE_SIZE][MAZE_SIZE]={
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'}
};

int main(){
    queue<Location2D> locQueue;
    Location2D entry(1,0);
    locQueue.push(entry);

   while(locQueue.empty() == false){
        Location2D here = locQueue.front(); //스택 상단 객체 복사
        locQueue.pop(); //상단 객체 삭제

        int r = here.row;
        int c = here.col;
        printf("현재 위치 : (%d,%d)\n",r,c); //현재위치 출력

        if(map[r][c]=='x'){
            printf("탐색 성공!!\n");
            return 1;
        }else{
            map[r][c] = '.'; //출구 x가 아니면 지나옴처리 .하기
            if(isValidLoc(r-1,c)) locQueue.push(Location2D(r-1,c));
            if(isValidLoc(r+1,c)) locQueue.push(Location2D(r+1,c));
            if(isValidLoc(r,c-1)) locQueue.push(Location2D(r,c-1));
            if(isValidLoc(r,c+1)) locQueue.push(Location2D(r,c+1));

        }
    }
    printf("미로탐색 실패 ..\n");
    return 1;
}
