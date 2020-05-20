//
// Created by Gil on 19/05/2020.
//

#ifndef DATASTRUCTURES_HASHTABLE_H
#define DATASTRUCTURES_HASHTABLE_H


#include <cmath>

#define NO_ELEMENT (-1)

template <class T>
class HashTableCell {
    T *value;
    int key;
public:
    HashTableCell() : value(nullptr), key(NO_ELEMENT) {}
    HashTableCell(T *val, int k) : value(val), key(k) {}
    ~HashTableCell() { if(!value) delete value; }
    T getValue() { return value; }
    int getKey() { return key; }
    void setKey(int k) { key = k;}
};


// Double hashing
template <class T>
class HashTable {
    HashTableCell<T> *hash_table;
    int dimension;
    int num_elements;
    double alpha;
    static const int BASE_DIMENSION = 113;  // some prime number

    void copy(HashTableCell<T> *element) {
        double hashing_func = BASE_DIMENSION * frac(element->getKey());
        int res = ((int)floor(hashing_func)) % dimension;
        while(hash_table[res].getKey() != NO_ELEMENT) {
            res = (res + 1) % dimension;
        }
        hash_table[res] = *element;
    }

    void rehash() {
        int old_dimension = dimension;
        if(num_elements == dimension) {
            dimension = 2 * dimension;  // table is full
        } else {
            dimension = dimension / 2;  // only quarter or less of the table in use
        }
        HashTableCell<T> *new_hash_table = new HashTableCell<T>[dimension];
        HashTableCell<T> *tmp = hash_table;
        hash_table = new_hash_table;
        for(int i=0 ; i < old_dimension ; i++) {
            copy(&hash_table[i]);
        }
        delete[] tmp;
    }

    double frac(int key) {
        double result = key * alpha;
        return (result - floor(result));
    }

public:
    HashTable() {
        hash_table = new HashTableCell<T>[BASE_DIMENSION];
        dimension = BASE_DIMENSION;
        num_elements = 0;
        alpha = ((sqrt(5) - 1)/2);  //  uniform dispersal
    }

    ~HashTable() {
        delete[] hash_table;
    }

    void insert(T value, int key) {
        if(num_elements == dimension || (num_elements < (dimension / 4) && (num_elements >= BASE_DIMENSION))) {
            rehash();
        }
        if(member(key) != NO_ELEMENT) {
            return;
        }
        HashTableCell<T> *new_element = new HashTableCell<T>(&value, key);
        copy(new_element);
        num_elements++;
    }

    void remove(int key) {
        if(num_elements == 0 || key < 0) {
            return;
        }
        int index = member(key);
        if(index == NO_ELEMENT) {
            return;
        }
        hash_table[index].setKey(-1);
        num_elements--;
        if(num_elements < (dimension / 4) && (num_elements >= BASE_DIMENSION)) {
            rehash();
        }
    }

    // returns num>=0 if element found, -1 otherwise.
    int member(int key) {
        if(num_elements == 0) {
            return NO_ELEMENT;
        }
        double hashing_func = BASE_DIMENSION * frac(key);
        int res = ((int)floor(hashing_func)) % dimension;
        while(hash_table[res].getKey() != key) {
            if(hash_table[res].getKey() != NO_ELEMENT) {
                return NO_ELEMENT;
            }
            res = (res + 1) % dimension;
        }
        return (hash_table[res].getKey() == key) ? res : NO_ELEMENT;
    }

    int getDimension() {
        return dimension;
    }

    int getNumElements() {
        return num_elements;
    }
};


#endif //DATASTRUCTURES_HASHTABLE_H
