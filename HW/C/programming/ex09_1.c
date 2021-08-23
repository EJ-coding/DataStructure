#include <stdio.h>
//my_print('*', 1); // * 문자와 1을 입력하였으므로 * 문자 한 개 출력
void my_print(char ch, int num){
    while(num != 0){
        printf("%c ",ch);
        num --;
    }
}
//정수 값을 인자로 받아서 약수를 출력하는 divisor 함수
void divisor(int num){
    for( int i =1 ; i <= num ;i++){
        if(num % i == 0){
            printf("%d ",i);
        }
    }
}

//int is_prime(int n)
int is_prime(int n){
    int cnt;//소수라면 cnt=2
    for( int i =1 ; i <= n ;i++){
        if(n % i == 0){
            cnt++;
            if(cnt >2) return 0;
        }
    }
    return 1;
}
int main(){
    int num;
    char ch;
    int prime;

    num = 3;
    ch ='*';

    //my_print(ch,num);
    //divisor(10);
    prime = is_prime(1);
    printf("%d",prime);

}
