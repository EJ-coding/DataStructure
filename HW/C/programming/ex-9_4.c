#include <stdio.h>

//float my_cal(char, float, float);
float my_cal(char exp , float num1, float num2){
    float ans;

    switch(exp){
        case '/':
            ans = num1/num2;
            break;
        case '*':
            ans = num1*num2;
            break;
        case '+':
            ans = num1+num2;
            break;
        case '-':
            ans = num1 - num2;
            break;

    }

    return ans;

}

int main(void){
    /*
     * 
    연산자를 입력하세요 : 
    두 개의 숫자를 입력하세요 : 10 2.1
    결과값은 4.76입니다.
    */
   float num1, num2;
   char exp;

   printf("연산자를 입력하세요 : \n");
   scanf("%c",&exp);
   printf("두 개의 숫자를 입력하세요 : \n");
   scanf("%f %f",&num1, &num2);
   printf("결과값은 %.2f 입니다.",my_cal(exp,num1,num2));

   return 0;
   
}