#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
private:
	int len;//행렬의 길이
	int** matrix;//행렬포인터
    int* shortest_matrix; //최단 경로 저장 행렬
    bool* shortest_vertex; //최단경로 정점
    int* path;
    int vertex;

public:
	Graph(){ 
        this->len = 0; 
    }; // 생성자
	~Graph(); //소멸자

	void LoadMatrix(std::string& filename);	// 인자로 받은 파일명으로 파일에 있는 가중치 행렬을 읽어서 멤버 변수로 저장
	void PrintMatrix();	// 인접 행렬을 출력
    void PrintShortestPathWeight(int s);    // 시작 정점 s로부터 나머지 vertex까지의 최단 경로 출력
    void PrintShortestPath(int s);                     // 시작 정점 s로부터 나머지 vertex까지의 최단 경로 출력
    int GetSize();      // 행렬의 크기 반환 (n x n의 경우 n 반환)
    //추가한 메소드
    int GetShortestVertex();//최소 거리 정점들 반환
    void PrintPath(int front, int rear);

};

#endif