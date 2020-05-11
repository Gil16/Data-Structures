//
// Created by Gil on 11/05/2020.
//

#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H

#include <iostream>
#include "Utilities.h"

#define EMPTY_QUEUE 0


template<class T>
class Queue {
    node<T> *front;
    node<T> *back;
    int size;

public:
    Queue<T>() : front(nullptr), back(nullptr), size(EMPTY_QUEUE) {}

    ~Queue() {
        while(size > 0) {
            Dequeue();
        }
    }

    void Enqueue(T data) {
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

    void Dequeue() {
        if(!back) {
            return;
        }
        if(back == front) {
            return;
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

    bool Empty() {
        return (size == 0);
    }

    node<T>* GetFront() {
        return  front;
    }

    node<T>* GetBack() {
        return  back;
    }

    void PrintQueue() {
        node<T> *temp_node = back;
        for(int i=size ; i > 0 ; i--) {
            std::cout << "Node " << i << " value is: " << temp_node->data << std::endl;
            temp_node = temp_node->next;
        }
    }

};


#endif //DATASTRUCTURES_QUEUE_H
