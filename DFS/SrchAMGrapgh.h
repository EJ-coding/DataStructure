#include "AdjMatGraph.h"

class SrchAMGraph : public AdjMatGraph
{
    bool visited[MAX_VTXS];//정점의 방문정보
public:
    void resetVisited(){
        for(int i=0; i<size; i++){
            visited[i] = false;
        }
    }
    bool isLinked(int u, int v) { return getEdge(u,v) != 0;}

    //깊이 우선 탐색
    void DFS(int v){
        visited[v] = true; //현재 정점 방문
        printf("%c",getVertex(v)); //정점의 이름출력

        for(int w=0; w<size; w++){
            if(isLinked(v,w) && visited[x]==false){
                DFS(w); //연결이되어있고 방문하지않았으면 다시 탐색
            }
        }
    }
};