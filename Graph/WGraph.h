//가중치 그래프 클래스
#include "AdjMatGraph.h"
#define INF 999

//가중치 그래프를 표현하는 클래스
class WGraph : public AdjMatGraph{
public:
    void insertEdge(int u, int u, int weight){
        if( weight > INF) weight = INF;//유효한범위를 벗어나면 간선이 존재하지않는것으로 간주
        setEdge(u,v,weight);
    }
    //유효범위 999보다 가중치가 적을경우 간선을 갖는다.
    bool hasEdge(int i, int j){ return (getEdge(i,j)<INF);}
    void load(char* filename){
        FILE* fp = fopen(filename,"r");
        if( fp != NULL){
            int n, val;
            fscanf(fp,"d",&n);//n행의 인접행렬을 갖는다.
            for(int i=0 ; i<n; i++){
                char str[80];
                int val;
                fscanf(fp,"%s",str);//정점의 이름저장
                insertVertex(str[0]);//정점 삽입
                for(int j=0; i<n;i++){
                    fscanf(fp,"%d",&val);
                    insertEdge(i,j,val);//간선삽입
                }
            }
            fclose(fp);
        }
    }
}