#include "Node2.h"
class DbLinkedList{
    Node2 org; //헤드노드
public:
    DbLinkedList() : org(0){}
    ~DbLinkedList()     { while( !isEmpty() ) delete remove(0);}
    Node2* getHead()    { return org.getNext();}
    bool isEmpty()      { return getHead() == NULL;}

    //pos번째 노드 반환 
    Node2* getEntry(int pos){
        Node2* n = &org;
        for(int i=-1 ; i<pos ;i++,n=n->getNext()){
            if( n==NULL) break;
        }
        return n;

    }

    //pos위치에 노드 삽입
    void insert(int pos, Node2* n){
        Node2* prev = getEntry(pos-1);
        if(prev != NULL){
            prev->insertNext(n);
        }
    }

    //pos위치 노드 삭제
    Node2* remove(int pos){
        Node2* n = getEntry(pos);
        return n->remove();
    }
    //값이 val인 노드 탐색
    Node2* find(int val){
        for( Node2* p = getHead(); p != NULL; p= p->getNext()){
            if(p->hasData(val)) return p;
        }
    }
    void replace(int pos, Node2* n){
        Node2* prev = getEntry(pos-1);
        if( prev != NULL){
            delete prev->getNext()->remove();
            prev->insertNext(n);
        }
    
    }

    int size(){
        int count = 0;
        for(Node2* p = getHead(); p != NULL; p=p->getNext()){
            count++;
        }
        return count;
    }

    void display(){
        printf("[이중연결리스트 항목 수 : %2d",size());
        for( Node2* p = getHead(); p != NULL; p=p->getNext()){
            p->display();
        }
        printf("\n");
    }

    void clear(){
        while (!isEmpty())
        {
            delete remove(0);
        }
        
    }

};