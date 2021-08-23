#include "BinaryNode.h"
#include <stdlib.h>
//레벨 순회 
#define MAX_QUEUE_SIZE 100

inline void error(char* str){
    //str에 들어온 문자열을 s형으로 stderr에 보낸다.
    fprintf(stderr,"%s\n", str);
    exit(1);
};

class CircularQueue{
    int front;  //첫번째 요소 앞의 위치
    int rear;   //마지막 요소 위치
    BinaryNode* data[MAX_QUEUE_SIZE];//요소들의 배열
public:
    CircularQueue()     { front = rear = 0;}
    bool isEmpty()      { return front == rear;}
    bool isFull()       { return (rear+1)%MAX_QUEUE_SIZE == front;}

    void enqueue(BinaryNode* n){
        if(isFull()){
            error("Error: Queue is full.\n");
        }else{
            rear = (rear+1) % MAX_QUEUE_SIZE;
            data[rear] = n;
        }
    }
    BinaryNode* dequeue(){
        if(isEmpty()){
            error("Error: Queue is empty.\n");
        }else{
            front = (front+1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
};

