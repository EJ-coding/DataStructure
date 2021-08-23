#include "DbLinkedList.h"

int main(){
    DbLinkedList list;
    list.insert(0, new Node2(10));
    list.insert(0, new Node2(20));
    list.display();

    list.insert(1,new Node2(30));
    list.insert(list.size(),new Node2(40));//마지막위치에40삽입
    list.display();

    list.remove(2);
    list.remove(list.size()-1);//마지막항목삭제
    list.display();

    list.replace(1, new Node2(50));
    list.display();
}