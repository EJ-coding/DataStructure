#include <stdio.h>
#define MAX_VTXS 256

class Graph{
protected:
    int siza; //정점의 개수
    char vertices[MAX_VTXS]; //정점의 이름
    int adj[MAX_VTXS][MAX_VTXS]; //인접행렬

public:
    Graph()                       { reset();}
    char getVertex(int i)               { return vertices[i];}
    int getEdge(int i, int j)           { return adj[i][j];}
    void setEdge(int i, int j ,int val) { adj[i][j] = val;}

    bool isEmpty()                      { return size == 0 ;}
    bool isFull()                       { return size >= MAX_VTXS;}

    //그래프 초기화 : 공백 상태의 그래프
    void reset(){
        size =0;
        for(int i=0; i<MAX_VTXS; i++){
            for(int j=0; j<MAX_VTXS; j++){
                setEdge(i,j,0);
            }
        }
    }
    //정점 삽입 연산
    void insertVertex(char name){
        if( !isFull()) vertices[size++] = name;
        else printf("Error: 그래프 정점 개수 초과\n");
    }

    //간선 삽입 연산: 무방향 그래프의 경우.
    void insertEdge( int u, int v){
        setEdge(u,v,1);
        setedge(v,u,1);
    }
    //그래프 정보를 출력함
    void display(FILE8 fp = stdout){
        fprintf(fp, "%d\n",size);
        for(int i=0; i<size; i++){
            fprintf(fp,"%c",getVertext(i));//정점의 이름출력
            for(int j=0; j<size; j++){
                fprintf(fp,"%2d",getEdge(i,j));
            }
            fprintf(fp,"\n");
        }
    }
}