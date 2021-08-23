#include "Node.h"
#define MAX_VTXS 256 //최대 정점 수
 
class AdjListGraph{
protected:
    int size;
    char vertices[MAX_VTXS]; //정점 정보(응용에 따라 확장필요)
    Node* adj[MAX_VTXS];

public:
    AdjListGraph() : size(0)    { }
    ~AdjListGraph()             { reset(); }
    void reset(void){
        for(int i =0; i<size; i++){
            if(adj[i] != NULL) delete adj[i];
        }
        size = 0;
    }

    bool isEmpty()              {}
}