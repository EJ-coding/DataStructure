//#include <iostream>
#include <cstdio>
#include <cstdlib>

//오류 처리 함수
inline void error(char *message){
    printf("%s\n", message);
    exit(1);
}

const int MAX_STACK_SIZE = 20;//스택 최대 크기 설정

class ArrayStack{
    int top; //요소의 개수
    int data[MAX_STACK_SIZE]; //

public:
    ArrayStack(){ top = -1; }// 스택 생성자 
    ~ArrayStack(){}
    bool isEmpty(){ return top == -1;}
    bool isFull(){  return top == MAX_STACK_SIZE-1; }

    void push(int e ){
        if(isFull()) error("스택이 가득 찼습니다.overflow!!");
        data[++top] = e;
    }

    int pop(){
        if(isEmpty()) error("스택이 비어있습니다.");
        return data[top--];
    }

    int peek(){
        if(isEmpty()) error("스택이 비어있습니다.");
        return data[top];
    }

    void display(){
        printf("[스택 항목의 수 = %2d] ==> ", top+1); // top이 인덱스 번호라서 스택항목개수는 top+1
        for(int i= 0; i <= top ;i++){
            printf("<%2d >",data[i]);
        }
        printf("\n");

    }
};