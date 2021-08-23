#include <stack>//stack STL사용
#include "Location2D.h"
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
//(r,c)가 갈 수 있는 위치인지 검사
bool isValidLoc( int r, int c){
    if( r<0 || c<0 || r>= MAZE_SIZE){
        return false;
    }else{
        return map[r][c] == '0' || map[r][c] == 'x';
    }
}
//미로 탐색
int main(){
    stack<Location2D> locStack; //위치 스택 객체 생성
    Location2D entry(1,0); //입구 객체
    locStack.push(entry); //스택에 입구 위치 삽입

    while(locStack.empty() == false){
        Location2D here = locStack.top(); //스택 상단 객체 복사
        locStack.pop(); //상단 객체 삭제

        int r = here.row;
        int c = here.col;
        printf("현재 위치 : (%d,%d)\n",r,c); //현재위치 출력

        if(map[r][c]=='x'){
            printf("탐색 성공!!\n");
            return 1;
        }else{
            map[r][c] = '.'; //출구 x가 아니면 지나옴처리 .하기
            if(isValidLoc(r-1,c)) locStack.push(Location2D(r-1,c));
            if(isValidLoc(r+1,c)) locStack.push(Location2D(r+1,c));
            if(isValidLoc(r,c-1)) locStack.push(Location2D(r,c-1));
            if(isValidLoc(r,c+1)) locStack.push(Location2D(r,c+1));

        }
    }
    printf("미로탐색 실패 ..\n");
    return 1;
}