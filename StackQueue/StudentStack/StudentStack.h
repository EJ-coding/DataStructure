#include "Student.h"
const int MAX_STACK_SIZE = 100; //스택 최대 크기

inline void error(char* str){
    printf("%s\n",str);
    exit(1);
}

class StudentStack{
    int top;
    Student data[MAX_STRING];

public:
    StudentStack() { top = -1; }
    bool isEmpty(){ return top == -1; }
    bool isFull(){ return top == MAX_STACK_SIZE-1;}
    //if you want "call by reference" -> push(Student &e)
    //call by value
    void push(Student e){
        if(isFull()) error("stack overflow!!");
        data[++top] = e;
    }

    Student pop(){
        if(isEmpty()) error("stack is empty..");
        return data[top--];
    }

    Student peek(){
        if(isEmpty()) error("stack is empty..");
        return data[top];
    }

    void display(){
        printf("[전체 학생의 수 = %d ]\n", top+1);
        for (int i =0 ; i <= top ; i++){
            data[i].display();
        }
        printf("\n");
    }
};