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
	Node *n = head->getNext();
	// Node *p = tail->getPrev();
	delete head;
	// delete tail;
	for(int i = 0; i < nodeLength; i++)
	{
		head = n;
		n = n->getNext();
		delete head;
		// tail = p;
		// p = p -> getPrev();
		// delete p;
	}
}
//new data insert
void LinkedList::Append(int data)
{
	Node *newNode = new Node(data);

	// tail이 새로운 노드 가리킴
	tail->insertNext(newNode);
	newNode->insertPrev(tail);
    //새로 추가된 노드는 마지막tail노드가 된다.
	tail = newNode;
	nodeLength++; //data추가할때마다 노드 길어진다
	
	
}	
//앞에 data추가 이중리스트 모양생각하기
void LinkedList::Prepend(int data){
	Node *newNode = new Node(data);	
	//노드가 비었을때도 구분
	if(nodeLength == 0)	
	{
		//dummynode와 newNode가 연결된 상태 : 이중리스트형태로
		//head(dummynode)의 next는 새로운 노드를 가리킴
		head->insertNext(newNode);
		//newNode의 prev는 dummynode가리킴
		newNode->insertPrev(head);
		//dummynode의 tail은 새로운 노드를 가리킴
		tail = newNode;	
	}else{
		// newNode의 prev는 dummynode 가리킴
		newNode->insertPrev(head);
		// newNode는 dummynode다음에 온다
		newNode->insertNext(head->getNext());
		// newNode의 prev는 더미노드의 next가리킴
		head->getNext() -> insertPrev(newNode);
		head->insertNext(newNode);
	//}
	nodeLength++;
	// 더미노드의 next ->새로운 노드
	

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
		cout << p-> getData() <<" ";
		p = p->getNext();
	}
	cout << endl;
}


// List에 있는 모든 Node를 tail부터 역순으로 출력
//이중리스트라 마지막노드의 prev를 따라가며 출력
void LinkedList::PrintReverse(){
	for(int i = 0; i < nodeLength; i++)
	{
		cout <<  tail->getData() <<" ";
		tail = tail->getPrev();
	}
	cout << endl;

}      