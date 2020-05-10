//
// Created by Gil on 10/05/2020.
//

#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H


#include <iostream>

#define EMPTY_LIST 0

template<class T>
struct node {
    node<T> *next;
    T data;
};

template<class T>
class LinkedList {
    node<T> *head;
    node<T> *tail;
    int size;

public:
    LinkedList<T>() : head(nullptr), tail(nullptr), size(EMPTY_LIST) {}

    ~LinkedList() {
        for(int i=size-1 ; i >= 0 ; i--){
            RemoveNodeByIndex(i);
        }
    }

    void AddNode(T data) {
        if(!head) {
            head = new node<T>();
            head->data = data;
            head->next = nullptr;
            tail = head;
        } else {
            if(head == tail) {
                tail = new node<T>();
                tail->data = data;
                tail->next = nullptr;
                head->next = tail;
            } else {
                node<T> *tempNode = new node<T>();
                tempNode->data = data;
                tempNode->next = nullptr;
                tail->next = tempNode;
                tail = tempNode;
            }
        }
        size++;
    }

    void RemoveNodeByIndex(int index) {
        if(index >= size || index < 0) {
            return;
        }

        node<T> *tempNode;
        if(index == 0 && !head) {
            return;
        } else if(index == 0) {
            tempNode = head->next;
            delete head;
            head = tempNode;
        } else {
            node<T> *beforeIndex = GetNodeByIndex(index);
            tempNode = beforeIndex->next;
            beforeIndex->next = tempNode->next;
            delete tempNode;
        }
        size--;
    }

    node<T>* GetNodeByIndex(int index) {
        if(index >= size || index < 0) {
            return nullptr;
        }

        node<T> *it = head;
        for(int i=0 ; i < size ; i++) {
            if(i == index) {
                return it;
            }
            it = it->next;
        }
        return nullptr; // unreachable
    }

    node<T>* operator[](int index) {
        return GetNodeByIndex(index);
    }

    void PrintList() {
        node<T> *tempNode = head;
        for(int i=0 ; i < size ; i++) {
            std::cout << "Node " << i << " value is: " << tempNode->data << std::endl;
            tempNode = tempNode->next;
        }
    }
};


#endif //DATASTRUCTURES_LINKEDLIST_H
