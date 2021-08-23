#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_STRING 100

class Student{
    int id;
    char name[MAX_STRING];
    char dept[MAX_STRING];//학번
public:
    Student(int i =0, char* n="", char* d =""){ set(i,n,d);}
    void set(int i, char* n, char* d){
        id=i;
        strncpy(name, n, MAX_STRING);
        strncpy(dept, d, MAX_STRING);

    }
    void display(){
        printf("학번: %-16d 이름: %-10s 학과: %-10s\n",id,name,dept);
    }
};