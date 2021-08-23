#include "HeapNode.h"
#define MAX_ELEMENT 200
class MaxHeap
{
    MaxHeap() : size(0) {}
    bool isEmpty()      { return size == 0;}
    bool isFull()       { return size == MAX_ELEMENT-1;} //배열0번 요소 사용안함

    HeapNode& getParent(int i){ return node[i/2];}
    HeapNode& getLeft(int i)  { return node[i*2];}
    HeapNode& getRight(int i) { return node[i*2-1];}//오른쪽 자식노드

    void insert(int key){
        if(isFull()) return; //힙이 가득 찬 경우
        int i = ++size; //증가된 힙 크기 위치에서 시작
        
        //트리를 거슬러 올라가면서 부모 노드와 비교
        while( i!=1 && key>getParent(i).getKey()){//루트가 아니면서 추가할 값이 부모노드 키값보다 클때 교환
            node[i] = getParent(i);//부모노드를 자신노드로 가져옴
            i /=2; //한 레벨 상승

        }
        node[i].setKey(key);//최종위치에 데이터 복사
    }    
    HeapNode remove(){
        if(isEmpty()) return NULL;
        HeapNode item = node[1]; //루트 노드 (삭제될 요소)
        HeapNode last = node[size--]; //힙의 마지막노드 삭제될거라 후위 감소
        int parent = 1; //루트 노드
        int child = 2; //루트의 왼쪽 자식위치

        while( child<=size ){//힙 트리를 벗어나지 않는동안
            //현재 노드값보다 값이 큰 자식노드를 찾는다.  
            if( child<size && getLeft(parent).getKey() < getRight(parent).getKey()){
                child++; //child : 더 큰 자식노드의 인덱스
            }
            //마지막 노드가 자식값보다 크면 이동완료
            if(last.getKey() >= node[child].getKey())   break;

            //아니면 한단계 아래로 이동
            node[parent] = node[child];
            parent = child;
            child *=2;
        }

        node[parent] = last; 
        return item; //루트 노드 반환

    }
    HeapNode find()    { return node[1];}

    void display(){
        for(int i =1, level=1; i <= size; i++){
            if ( i ==level){
                printf("\n");
                level *= 2;
            }
            node[i].display();
        }
        printf("\n===================================");
    }
};