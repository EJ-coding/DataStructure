#include <stdio.h>

void set_to_zero(int a[ ], int size){
    while(size>0){
        a[size-1] = 0 ;//초기화
        size--;
    }
}
int main(){
    int a[10];
    set_to_zero(a,10);
    for(int i =0; i<10; i++){
           printf("%d",a[i]);
    }
 
}
