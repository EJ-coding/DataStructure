#include <stdio.h>
class Node{
    Node* link; //다음 노트 가리키는 포인터 변수 
    int data;
public:
    Node(int val = 0) : data(val), link(NULL){}
    Node* getLink()     { return link;}
    void setLink(Node* next)    { link = next;}
    void display()      { printf("< %2d >",data); }

};