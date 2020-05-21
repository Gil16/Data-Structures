#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H


#include "Utilities.h"
#include "Exceptions.h"

#define STACK_MAX_SIZE 1000

template<class T>
class Stack {
    int top;
    T data[STACK_MAX_SIZE];
public:
    Stack() : top(0) {}
    ~Stack() { delete[] data; }

    bool push(const T& element);
    void pop();
    T& getTop();
    bool isEmpty() { return (top == 0); }
    int size() { return top; }
};


template <class T>
bool Stack<T>::push(const T& element) {
    if(top >= STACK_MAX_SIZE - 1) {
        return false;
    } else {
        data[top++] = element;
        return true;
    }
}

template <class T>
void Stack<T>::pop() {
    if(top <= 0) {
        throw EmptyException();
    }
    top--;
}

template <class T>
T& Stack<T>::getTop() {
    if(top <= 0) {
        throw "Stack Empty";
    } else {
        return data[top - 1];
    }
}

#endif //DATASTRUCTURES_STACK_H
