//
// Created by Gil on 16/05/2020.
//

#ifndef DATASTRUCTURES_HEAP_H
#define DATASTRUCTURES_HEAP_H

#define MIN_INDEX 1

// array heap
template <class T>
class MinHeap {
    T* heap;
    int heap_size;
    int num_elements;
    void siftDown(int index) {
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
            if((heap[index] < heap[double_index]) && (getMin() < heap[double_index + 1])) {
                return;
            }
            int min = (heap[double_index] < heap[double_index + 1]) ? double_index : (double_index + 1);
            swap(heap[index], heap[min]);
            siftDown(min);
        }

    }
    void siftUp(int index) {
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
    void siftHeap() {
        for(int i = (num_elements / 2) ; i > 0 ; i--) {
            siftDown(i);
        }
    }
    static void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }

public:
    MinHeap(T* array, int length) {
        heap_size = 2*length + 1;
        num_elements = length;
        heap = new T[heap_size];

        for(int i=MIN_INDEX ; i<= num_elements ; i++) {
            heap[i] = array[i-1];
        }
        siftHeap();
    }
    ~MinHeap() {
        if(heap) {
            delete[] heap;
        }
    }

    void insert(T* element) {
        if(!element) {
            return;
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

    void deleteMin() {
        if(num_elements == 0) {
            return;
        }
        swap(heap[MIN_INDEX], heap[num_elements]);
        num_elements--;
        siftDown(MIN_INDEX);
    }

    void decElement(int position, T* updated) {
        if(num_elements == 0 || position < 0 || position > num_elements ) {
            return;
        }
        // Cant increase the element
        if(heap[position] < updated) {
            return;
        }
        heap[position] = updated;
        siftUp(position);
    }

    T getMin() {
        return heap[MIN_INDEX];
    }

    int getNumElements() {
        return num_elements;
    }

};

#endif //DATASTRUCTURES_HEAP_H
