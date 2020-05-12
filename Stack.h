//
// Created by Gil on 12/05/2020.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#define STACK_MAX_SIZE 1000

template<class T>
class Stack {
    int top;
    T data[STACK_MAX_SIZE];

public:
    Stack() : top(0) {}

    ~Stack() { delete[] data; }

    bool Push(const T& element) {
        if(top >= STACK_MAX_SIZE - 1) {
            return false;
        } else {
            data[top++] = element;
            return true;
        }
    }

    void Pop() {
        if(top <= 0) {
            return;
        }
        top--;
    }

    T& Top() {
        if(top <= 0) {
            throw "Stack Empty";
        } else {
            return data[top - 1];
        }
    }

    bool IsEmpty() {
        return (top == 0);
    }

    int Size() {
        return top;
    }
};

#endif //DATASTRUCTURES_STACK_H
