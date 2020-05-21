#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H


#include "Utilities.h"
#include "Exceptions.h"

#define EMPTY_LIST 0

template <class T>
class LinkedList {
    node<T> *head;
    node<T> *tail;
    int size;
public:
    LinkedList<T>() : head(nullptr), tail(nullptr), size(EMPTY_LIST) {}
    ~LinkedList() { for(int i=size-1 ; i >= 0 ; i--) removeNodeByIndex(i); }

    void addNode(T data);
    void removeNodeByIndex(int index);
    node<T>* getNodeByIndex(int index);
    int getListSize() const { return size; }
    node<T>* getListHead() const { return head; }
    node<T>* getListTail() const { return tail; }
    LinkedList<T>& operator=(const LinkedList<T>& list);
    node<T>* operator[](int index) { return getNodeByIndex(index); }
};


template <class T>
void LinkedList<T>::addNode(T data) {
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

template <class T>
void LinkedList<T>::removeNodeByIndex(int index) {
    if(index >= size || index < 0) {
        throw InvalidInputException();
    }
    node<T> *tempNode;
    if(index == 0 && !head) {
        throw EmptyException();
    } else if(index == 0) {
        tempNode = head->next;
        delete head;
        head = tempNode;
    } else {
        node<T> *beforeIndex = getNodeByIndex(index);
        tempNode = beforeIndex->next;
        beforeIndex->next = tempNode->next;
        delete tempNode;
    }
    size--;
}

template <class T>
node<T>* LinkedList<T>::getNodeByIndex(int index) {
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
    return nullptr;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list) {
    head = list.getListHead();
    tail = list.getListTail();
    size = list.getListSize();
    return *this;
}

#endif //DATASTRUCTURES_LINKEDLIST_H
