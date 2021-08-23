#include <iostream>
#include "list.h"

using namespace std;

LinkedList::LinkedList()
{
	head = new Node();//dummy node인 head생성
	tail = head;//처음엔 꼬리==머리
	nodeLength = 0;//처음 노드길이 0으로 초기화
}

//메모리 해제
LinkedList::~LinkedList()
{
	Node *p = head->getNext();
	delete head;
	for(int i = 0; i < nodeLength; i++)
	{
		head = p;
		p = p->getNext();
		delete head;
	}
}
//new data insert
void LinkedList::Append(int data)
{
	Node *newNode = new Node(data);

	// tail이 새로운 노드 가리킴
	tail->insertNext(newNode);
    //새로 추가된 노드는 마지막tail노드가 된다.
	tail = newNode;
	nodeLength++; //data추가할때마다 노드 길어진다
}	

int LinkedList::Length()	
{
	return nodeLength;
}
//head 부터 차례대로 출력
void LinkedList::Print()
{
	Node *p = head->getNext();

	for(int i = 0; i < nodeLength; i++)
	{
		cout << p->getData() <<" ";
		p = p->getNext();
	}
	cout << endl;
}