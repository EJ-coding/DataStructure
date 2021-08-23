#include <stdio.h>



int main(void)
{
    int grade[5];
    int i,j,tmp;
    float sum;
   // 성적 입력
   printf("성적을 입력하세요 : ");

   for(i = 0; i < 5; i++) {
       scanf("%d", &grade[i]);
    }
    // 성적 정렬 : 버블 정렬
    for (i = 0; i < 5; i++)
        for (j = 0; j< 4-i; j++)
            if (grade[j] < grade[j+1]){
                tmp = grade[j];
                grade[j] = grade[j+1];
                grade[j+1] = tmp;
            }
    // 성적순으로 출력
    for (i = 0; i < 5; i++)
        printf("%d등 %d 점 ", i+1,grade[i]);
    printf("\n");
    //전체 평균
    for(i = 0; i<5; i++){
        sum += grade[i];
    }
    printf("전체 평균: %.2f 점",sum/5.0);
    return 0;

}