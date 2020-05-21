#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H


#include "Utilities.h"
#include "Exceptions.h"

#define EMPTY_QUEUE 0

template <class T>
class Queue {
    node<T> *front;
    node<T> *back;
    int size;
public:
    Queue<T>() : front(nullptr), back(nullptr), size(EMPTY_QUEUE) {}
    ~Queue() { while(size > 0) dequeue(); }

    void enqueue(T data);
    void dequeue();
    bool empty() { return (size == 0); }
    node<T>* getFront() { return  front; }
    node<T>* getBack() { return  back; }
};


template <class T>
void Queue<T>::enqueue(T data) {
    if(!front) {
        front = new node<T>();
        front->next = nullptr;
        front->data = data;
        back = front;
    } else {
        auto temp_node = new node<T>();
        temp_node->data = data;
        temp_node->next = back;
        back = temp_node;
    }
    size++;
}

template <class T>
void Queue<T>::dequeue() {
    if(!back) {
        throw EmptyException();
    }
    if(back == front) {
        throw EmptyException();
    }
    auto temp_node = back;
    while(temp_node->next != front) {
        temp_node = temp_node->next;
    }
    temp_node->next = nullptr;
    delete front;
    size--;
    front = temp_node;
}

#endif //DATASTRUCTURES_QUEUE_H
