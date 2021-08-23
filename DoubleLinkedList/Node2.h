#include <stdio.h>

class Node2{
    Node2* prev;
    Node2* next;
    int data;
public:
    Node2(int val=0) : data(val), prev(NULL), next(NULL){}
    Node2* getPrev()        { return prev;}
    Node2* getNext()        { return next;}
    void setPrev(Node2* p)  { prev = p;}
    void setNext(Node2* n)  { next = n;}
    void display()          { printf("<%2d>",data);}
    bool hasData(int val)   { return data == val;}

    //현재 노드 다음에 새로운 노드 n삽입
    void insertNext(Node2* n){
        if( n != NULL){
            n->prev = this; //추가될 노드n의 prev가 현재노드this가리킴
            n->next = next;
            if(next != NULL) next->prev = n;
            next = n;
        }
    }

    //현재 노드를 연결리스트에서 제거
    Node2* remove(){
        if(prev != NULL ) prev->next = next;
        if(next != NULL) next->prev = prev;
        return this;
    }
};