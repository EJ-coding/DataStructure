#ifndef _CIRCULARQUEUE_H
#define _CIRCULARQUEUE_H

class Queue{

if(rear == capacity-1) rear = 0;
else rear++;
//rear = (rear+1)%capacity;
private:
    T * queue;
    int front,
        rear,
        capacity;

public:
    template <class T>
    Queue(int queueCapacity);
    ~Queue();
    bool IsEmpty();
    T& Front();
    T& Rear();
    void Pop();

};

#endif
