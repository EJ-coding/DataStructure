#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "graph.h"
using namespace std;

int Graph::GetSize()
{
    return len;
}
int Graph::GetShortestVertex()
{
    int len = GetSize();
    //초기 상태
    int init = 999;
    int vertex_index = 0;

    for( int i = 0; i <len ; i++){
        if((shortest_matrix[i] < init)&& !shortest_vertex[i]){
            init = shortest_matrix[i];
            vertex_index = i;
        }
    }

    return vertex_index;
}
void Graph::PrintShortestPathWeight(int s)
{
	int len = GetSize();//길이 가져오기
    //배열 생성
	shortest_matrix = new int[len];
	shortest_vertex = new bool[len];
    path = new int[len];

	for(int i = 0; i < len; i++)
	{   
        //시작 정점으로부터 짧은 경로 탐색하기
		shortest_matrix[i] = 999;
        //초기화 
		shortest_vertex[i] = false;
        path[0] = -1;
       
	}
    shortest_matrix[s] = 0;
	
	for(int i = 0; i < len-2; i++)
	{
		int current = GetShortestVertex();//최소거리 정점 반환
		shortest_vertex[current] = true;
        //최단 정점이 아닌경우
		for(int j = 0; j < len ; j++)
		{
			if(!shortest_vertex[j])
			{
				if(shortest_matrix[current] + matrix[current][j] < shortest_matrix[j]){
                    shortest_matrix[j] = shortest_matrix[current] + matrix[current][j];
                    path[j] = current;
                }
			}
		}
	}
}
void Graph::PrintShortestPath(int s)
{

	vertex = s;
	PrintShortestPathWeight(vertex);

	for(int i = 0; i < len; i++)
	{
		if(s == i)
			continue;
		cout << vertex << " ";
		PrintPath(s, i);
		//cout << endl;
	}
}
void Graph::PrintPath(int front, int rear)
{
	if(path[rear] == -1)
		return;
	PrintPath(front, path[rear]);
	//cout << endl;
}
Graph::~Graph()	//소멸자 :매모리 해제
{
	for(int i = 0; i< len ; i++){
		delete[] matrix[i];
    }
	delete[] matrix; 
    delete[] shortest_matrix;
    delete[] shortest_vertex;
}

void Graph::LoadMatrix(string& filename)
{
	ifstream readFile;//파일을 읽어오기위해 열기
	string str;//한줄씩 읽어올 문장열 변수
    //파일 열기
	readFile.open(filename);
    //잘 열렸으면 한줄씩 읽어서 행렬정보가져오기
	if(readFile.is_open())
	{
		getline(readFile, str);//한줄읽어오기
        //행렬의 길이
		len = stoi(str, nullptr);//string to int
        //포인터 행렬 선언
		matrix = new int* [len];
        //각각 포인터가 가르치는 인접행렬 생성
		for(int i = 0; i< len; i++){
            matrix[i] = new int[len];
        }
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
		for(int j = 0; j<len; j++){
            cout << matrix[i][j] << " ";
        }
		cout << endl;
	}
}