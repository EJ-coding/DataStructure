#include <stdio.h>
/*
int n: 이동할 원반의 숫자
char from: 이동할 원반이 있는 출발지 탑
char by: 원반을 이동하는 과정에서 거쳐가는 탑
char to: 원반을 이동할 목적지 탑
*/

void Hanoi(int n, char from, char by, char to)
{
    if( n ==1) printf("%c=>%c\n",from,to);
    else{
        Hanoi(n-1,from,to,by);
        printf("%c=>%c\n",from,to);
        Hanoi(n-1,by,from,to);
    }
}

int main(){
    Hanoi(3,'A','B','C');
    /*
    A=>C
    A=>B
    C=>B
    A=>C
    B=>A
    B=>C
    A=>C
    */

}