#ifndef DATASTRUCTURES_HEAP_H
#define DATASTRUCTURES_HEAP_H

#include "Utilities.h"
#include "Exceptions.h"

#define MIN_INDEX 1

template <class T>
class MinHeap {
    T* heap;
    int heap_size;
    int num_elements;
    void siftDown(int index);
    void siftUp(int index);
    void siftHeap();
public:
    MinHeap(T* array, int length);
    ~MinHeap();

    void insert(T* element);
    void deleteMin();
    void decElement(int position, T* updated);
    T getMin() { return heap[MIN_INDEX]; }
    int getNumElements() { return num_elements; }
};


template <class T>
void MinHeap<T>::siftDown(int index) {
    if(index == num_elements) {
        return;
    }
    int double_index = 2*index;
    if((double_index > num_elements) || (double_index >= heap_size)) {
        return;
    }
    if((heap_size - 1) >= double_index && num_elements == double_index) {
        if((heap[index]) < heap[double_index]) {
            return;
        }
        swap(heap[index], heap[double_index]);
        siftDown(double_index);
    } else {
        if((heap[index] < heap[double_index]) && (heap[index] < heap[double_index + 1])) {
            return;
        }
        int min = (heap[double_index] < heap[double_index + 1]) ? double_index : (double_index + 1);
        swap(heap[index], heap[min]);
        siftDown(min);
    }
}

template <class T>
void MinHeap<T>::siftUp(int index) {
    if(num_elements == 1 || getMin() == heap[index]) {
        return;
    }
    if(heap[index/2] < heap[index]) {
        return;
    } else {
        swap(heap[index/2], heap[index]);
        siftUp(index/2);
    }
}

template <class T>
void MinHeap<T>::siftHeap() {
    for(int i = (num_elements / 2) ; i > 0 ; i--) {
        siftDown(i);
    }
}

template <class T>
MinHeap<T>::MinHeap(T* array, int length) {
    heap_size = (2 * length) + 1;
    num_elements = length;
    heap = new T[heap_size];
    for(int i=MIN_INDEX ; i<= num_elements ; i++) {
        heap[i] = array[i-1];
    }
    siftHeap();
}

template <class T>
MinHeap<T>::~MinHeap() {
    if(heap) {
        delete[] heap;
    }
}

template <class T>
void MinHeap<T>::insert(T* element) {
    if(!element) {
        throw NullPointerException();
    }
    if(heap_size-1 == num_elements) {
        T* new_heap = new T[2*heap_size + 1];
        for(int i=MIN_INDEX ; i < num_elements ; i++) {
            new_heap[i] = heap[i];
        }
        delete[] heap;
        heap = new_heap;
        heap_size = 2*heap_size + 1;
    }
    heap[num_elements + 1] = element;
    num_elements++;
    siftUp(num_elements);
}

template <class T>
void MinHeap<T>::deleteMin() {
    if(num_elements == 0) {
        throw EmptyException();
    }
    swap(heap[MIN_INDEX], heap[num_elements]);
    num_elements--;
    siftDown(MIN_INDEX);
}

template <class T>
void MinHeap<T>::decElement(int position, T* updated) {
    if(position < 0 || position > num_elements) {
        throw InvalidInputException();
    }
    if(num_elements == 0) {
        throw EmptyException();
    }
    // Cant increase the element
    if(heap[position] < updated) {
        throw InvalidInputException();
    }
    heap[position] = updated;
    siftUp(position);
}

#endif //DATASTRUCTURES_HEAP_H
