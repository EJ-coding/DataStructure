#include "ArrayList.h"
int main(){
    ArrayList list;

    list.insert(0,10);//list맨앞에 10 넣기
    list.insert(0,20); //list [ 30 20 10..]
    list.insert(0,30);
    list.insert(list.size(),40); // 마지막에 40 넣기
    list.insert(2,50); //list [ 30,50,20,10,40]
    list.display();

    list.remove(2);
    list.remove(list.size()-1);
    list.display();

    list.clear();
    list.display();
}