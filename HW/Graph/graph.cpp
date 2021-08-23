#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "graph.h"
using namespace std;

Graph::~Graph()	//소멸자 :매모리 해제
{
	for(int i = 0; i< len ; i++)
		delete[] matrix[i];
	delete[] matrix; 
}

void Graph::LoadMatrix(string& filename)
{
	ifstream readFile;//파일을 읽어오기위해 열기
	string str;//한줄씩 읽어올 문장열 변수

	readFile.open(filename);
	if(readFile.is_open())
	{
		getline(readFile, str);//한줄읽어오기
        //행렬의 길이
		len = stoi(str, nullptr);//string to int
        //포인터 행렬 선언
		matrix = new int* [len];
        //각각 포인터가 가르치는 인접행렬 생성
		for(int i = 0; i< len; i++)
			matrix[i] = new int[len];
	}

    //각 행렬의 행의 길이만큼 읽어온 후 저장
	for(int i = 0; i < len; i++)
	{
		getline(readFile, str);//한줄 씩 읽어오기
        //한줄씩 stream으로 전달
		stringstream stream(str);

		int num;
		int cnt = 0; 
		while(cnt < len)
		{
			for(int j = 0; j<len; j++)
			{
				stream >> num; //파일에서 읽어온 숫자를 행렬원소로 대입
				matrix[i][j] = num;
				cnt++;
			}
		}
	}
	readFile.close();
}
void Graph::PrintMatrix()
{
	for(int i = 0; i<len; i++)
	{
		for(int j = 0; j<len; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

//가중치 그래프 클래스
#include "AdjMatGraph.h"
#define INF 999

//가중치 그래프를 표현하는 클래스

void Graph::insertEdge(int u, int u, int weight){
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