#include <iostream>
#include "circularQueue.h"
//#include <queue>
using namespace std;

Queue<T>:: Queue (int queueCapacity): capacity (queueCapacity){
    if(capacity<1) throw "queue capacity must be >0 ";
    queue = new T[capacity];
    front = rear = 0;
}

Queue<T>:: ~Queue(){
    delete []queue;
}

inline bool Queue<T>::IsEmpty(){
    return front == rear;
}

inline T& Queue<T>::Front(){
    if(IsEmpty())throw "Queue is empty. No front element";
    return queue[(front+1)%capacity];
}

inline T& Queue<T> :: Rear(){
    if(IsEmpty()) throw "Queue is empty. No rear element";
    return queue[rear];
}

void Queue<T>::Pop(){
    if(isEmpty()) throw "Queue is empty. Cannot delete";
    front =(front+1)%capacity;
    queue[front].~T();
}

int main(){
    Queue = testQueue;

}