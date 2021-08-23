//dummy node == head node
#include <stdio.h>
class Node{
    Node* link; //다음 노드를 가리키는 포인터 변수
    int data; 
public:
    Node(int val = 0) : data(val),link(NULL) {}
    Node* getLink() { return link;}

    void setLink(Node* next)    { link = next;}
    void display()              { printf("<%2d >",data); }
    bool hasData(int val)       {return data == val;}

    //자신의 다음에 새로운 노드n을 삽입하는 함수
    void insertNext( Node *n){
        if( n != NULL){
            n->link = link;
            link = n; //기존link는 새로들어온 노드n을가리킨다.
        }
    }
    //자신의 다음 노드를 삭제
    Node* removeNext(){
        Node* removed = link; //현재노드의 link가 가리키는 마지막노드를 removed가 가리킴
        if(removed != NULL){
            link = removed->link; //현재노드의 Link를 removed의 link로 변경하므로서 현재노드의 다음노드를삭제한다
        }
        return removed;
    }
};