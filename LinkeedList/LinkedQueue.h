#include "Node.h"
class LinkedQueue{
    Node* front; //가장 먼저 삽입된 노드 포인터
    Node* rear; //마지막에 삽입된 노드 포인터 

public:
    LinkedQueue(): front(NULL), rear(NULL){ }
    ~LinkedQueue() { while(!isEmpty()) delete dequeue();}
    bool isEmpty() { return front == NULL; }

    //삽입연산 : 연결된 큐의 맨 뒤에 노드 삽입
    void enqueue(Node* p){
        if(isEmpty()) front = rear = p;
        else{
            //마지막 link가 p를 가르키게한다.
            rear->setLink(p); //  void setLink(Node* next)  { link = next;}
            //rear은 마지막 추가된 p를 가리킨다.
            rear = p;
        }
    }
    //삭제 연산 : 연결된 큐의 맨 앞 노드를 삭제
    Node* dequeue(){
        if(isEmpty()) return NULL;
        Node* p = front;//p가 기존의 front를 가리킨다.
        //front는 기존의 front의 link가 가리키는 것을 가리킨다.(기존front다음 노드를 가리킴)
        front = front->getLink(); //Node* getLink()     { return link;}
        if( front == NULL ) rear = NULL;//노드가 하나였는데 삭제될경우 front,rear모두 NULL
        return p;
    }
    Node* peek(){ return front;}
    void display(){
        printf("[큐 내용]:");
        for( Node* p = front; p != NULL; p=p->getLink()){
            p->display();
        }
        printf("\n");
    }
};