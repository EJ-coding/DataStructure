#include <stdio.h>
#include <string.h>
#include <iostream>

#define MAX_LIST_SIZE 100
using namespace std;
class ArrayList{
    int data[MAX_LIST_SIZE];
    int length; //항목들의 개수
public:
    ArrayList(void) { length=0; }//생성자 호출 시 length초기화
    //삽입 연산 :리스트의 pos번째에 항목e 추가
    void insert(int pos, int e){
        if( !isFull() && pos>=0 && pos<= length){
            for( int i = length; i>pos ; i--){
                data[i] = data[i-1];//뒤로 한칸씩 밀기
            }
            data[pos] = e;
            length++;//리스트 항목의 개수 증가
            
        }else{
            error("포화 상태 오류 또는 삽입 위치 오류");
        }
    }

    //삭제 연산: pos번째에 항목을 리스트에서제거
    void remove( int pos){
        if( !isEmpty() && 0<=pos && pos<length){
            for(int i= pos+1;i<length ; i++){
                data[i-1]= data[i];
            }
            length--;
        }else{
            error("공백상태 오류 또는 삭제 위치 오류");
        }
    }

    int getEntry(int pos){ return data[pos]; }//pos번째 항목을 반환
    bool isEmpty(){ return length == 0;}
    bool isFull(){ return length == MAX_LIST_SIZE;}//포화 상태 검사

    bool find(int item){
        for(int i=0; i<length; i++){
            if( data[i] == item){
                return true;
            }else{
                return false;
            }
        }
    }
    void replace(int pos, int e){
        data[pos] = e;
    }
    int size(){ return length;}
    void display(){
        printf("[배열로 구현한 리스트 전체 항목 수 = %d] : ",size());
        for(int i=0; i<size(); i++){
            printf("[%2d]",data[i]);
        }
        printf("\n");
    }
    void clear(){ length = 0;}//모든 요소 제거
    void error(string p){
        printf("%s",&p);
    }
};