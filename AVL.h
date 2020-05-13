//
// Created by Gil on 13/05/2020.
//

#ifndef DATASTRUCTURES_AVL_H
#define DATASTRUCTURES_AVL_H

#define MAX_BALANCE 2
#define MIN_BALANCE -2


template <class Data, class Key>
class AVLTreeNode
{
public:
    Data *data;
    Key *key;
    int balance;
    AVLTreeNode *left, *right, *parent;
    AVLTreeNode() : data(nullptr), key(nullptr), balance(0),left(nullptr), right(nullptr), parent(nullptr) {}
    AVLTreeNode(Data* d, Key* k, AVLTreeNode* t) : data(d),key(k), balance(0), left(nullptr), right(nullptr), parent(t) {}
    ~TreeNode(){
        if(left) {
            delete left;
        } if(right) {
            delete right;
        } if(key) {
            delete key;
        } if(data) {
            delete data;
        }
    }
};


template <class Data, class Key>
class AVLTree{
    AVLTreeNode<Data, Key> *root;
    int size;

    static int max(int a, int b) {
        return (a > b ? a : b);
    }
    // TODO: rotation functions: R, L -> RR,  LL, RL, LR
public:
    AVLTree() : root(nullptr), size(0) {}
    ~AVLTree() { if(root) { delete root; } }
    bool operator==(AVLTreeNode<Data, Key> &node1, AVLTreeNode<Data, Key> &node2) {
        return (*(node1.key) == *(node2.key));
    }

    bool insert(Data *data, Key *key) {
        if(!data || !key) {
            return false;
        }
        if(isKeyExists(key)) {
            return false;
        }
        if(!root) {
            root = new AVLTreeNode<Data, Key>(data, key, nullptr);
        } else {
            AVLTreeNode<Data, Key> *parent, *it = root;
            while(true) {
                parent = it;
                it = (*(it->key) > *key) ? it->left : it->right;
                if(!it) {
                    if(*(parent->key) > *key) {
                        parent->left = new AVLTreeNode<Data, Key>(data, key, parent);
                    } else {
                        parent->right = new AVLTreeNode<Data, Key>(data, key, parent);
                    }
                    // TODO: balance
                    break;
                }
            }
        }
        size++;
        return true;
    }

    void remove(Key *key) {

    }

    void reBalance(AVLTreeNode<Data, Key> *node) {

    }

    void setBalance(AVLTreeNode<Data, Key> *node) {
        node->balance = getHeight(node->left) - getHeight(node->right);
    }
    int getHeight(AVLTreeNode<Data, Key> *node) {
        if (!node){
            return -1;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
    bool isKeyExists(Key *key) {
        if(!root) {
            return false;
        }
        return find(key) != nullptr;
    }
    AVLTreeNode<Data, Key>* find(Key *key) {
        if(!key) {
            return nullptr;
        }
        AVLTreeNode<Data, Key>* iter = root;
        while (iter != nullptr) {
            if (*(iter->key) == *key) {
                return iter;
            } else {
                iter = (*(iter->key) > *key ? iter->left : iter->right);
            }
        }
        return nullptr;
    }
    AVLTreeNode<Data, Key>* getRoot() {
        return root;
    }

};

#endif //DATASTRUCTURES_AVL_H