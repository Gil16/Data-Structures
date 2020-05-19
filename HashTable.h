//
// Created by Gil on 19/05/2020.
//

#ifndef DATASTRUCTURES_HASHTABLE_H
#define DATASTRUCTURES_HASHTABLE_H


#include <math.h>

template <class T>
class HashTableCell {
    T value;
    int key;
public:
    HashTableCell() : value(nullptr), key(-1) {}
    HashTableCell(T val, int k) : value(val), key(k) {}
    ~HashTableCell() { if(!value) delete value; }
};



template <class T>
class HashTable {
    HashTableCell *hash_table;
    int dimension;
    int num_elements;
    double alpha;
    static const int BASE_DIMENSION = 113;  // some prime number
    void rehash() {
        int old_dimension = dimension;
        HashTableCell *new_hash_table;
        if(num_elements == dimension) {
            dimension = 2 * dimension;
        } else {
            dimension = dimension / 2;
        }
        new_hash_table = new HashTableCell[dimension];
        HashTableCell *tmp = hash_table;
        hash_table = new_hash_table;
        for(int i=0 ; i < old_dimension ; i++) {
            // TODO: add copy function
        }
        delete[] tmp;
    }
    double frac(int key) {
        double result = key * alpha;
        return (result - floor(result));
    }
public:
    HashTable() {
        hash_table = new HashTableCell[BASE_DIMENSION];
        dimension = BASE_DIMENSION;
        num_elements = 0;
        alpha = ((sqrt(5)-1)/2);  //  uniform dispersal
    }

    ~HashTable() {
        delete[] hash_table;
    }

    void insert() {

    }

    void remove() {

    }

    bool member() {

    }

    int getDimension() {
        return dimension;
    }

    int getNumElements() {
        return num_elements;
    }
};


#endif //DATASTRUCTURES_HASHTABLE_H
