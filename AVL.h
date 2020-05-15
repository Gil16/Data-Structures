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
    ~AVLTreeNode(){
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
    AVLTreeNode<Data, Key>* rotateLeft(AVLTreeNode<Data, Key> *a) {
        AVLTreeNode<Data, Key> *b = a->right;
        b->parent = a->parent;
        a->right = b->left;
        if(a->right != nullptr){
            a->right->parent = a;
        }
        b->left = a;
        a->parent = b;
        if(b->parent != nullptr) {
            if(b->parent->right == a) {
                b->parent->right = b;
            } else {
                b->parent->left = b;
            }
        }
        setBalance(a);
        setBalance(b);
        return b;
    }
    AVLTreeNode<Data, Key>* rotateRight(AVLTreeNode<Data, Key> *b) {
        AVLTreeNode<Data, Key> *a = b->left;
        a->parent = b->parent;
        b->left = a->right;

        if(b->left != nullptr) {
            b->left->parent = b;
        }
        a->right = b;
        b->parent = a;
        if(a->parent != nullptr) {
            if(a->parent->right == b) {
                a->parent->right = a;
            } else {
                a->parent->left = a;
            }
        }
        setBalance(b);
        setBalance(a);
        return a;
    }
    AVLTreeNode<Data, Key>* rotateLeftRight(AVLTreeNode<Data, Key> *n) {
        n->left = rotateLeft(n->left);
        return rotateRight(n);
    }
    AVLTreeNode<Data, Key>* rotateRightLeft(AVLTreeNode<Data, Key> *n) {
        n->right = rotateRight(n->right);
        return rotateLeft(n);
    }

public:
    AVLTree() : root(nullptr), size(0) {}
    ~AVLTree() { if(root) { delete root; } }
 /*   bool operator==(AVLTreeNode<Data, Key> &node1, AVLTreeNode<Data, Key> &node2) {
        return (*(node1.key) == *(node2.key));
    } */

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
                    reBalance(parent);
                    break;
                }
            }
        }
        size++;
        return true;
    }

    void remove(AVLTreeNode<Data, Key> *node) {
        if(!root || !node) {
            return;
        }
        if(!node->key) {
            return;
        }
        if(!isKeyExists(node->key)) {
            return;
        } else {
            AVLTreeNode<Data, Key> *node_parent = node->parent;
            // node is a leaf
            if(!node->right && !node->left) {
                if(!node_parent) {
                    root = nullptr;
                } else if(node_parent->left == node) {
                    node_parent->left = nullptr;
                } else {
                    node_parent->right = nullptr;
                }
                delete node;
                size--;
                reBalance(node_parent);
            }
            // node has only left son
            else if(!node->right) {
                if(!node_parent) {
                    root = node->left;
                    root->parent = nullptr;
                } else if(node_parent->left == node) {
                    node_parent->left = node->left;
                    node->left->parent = node_parent;
                } else {
                    node_parent->right = node->left;
                    node->left->parent = node_parent;
                }
                delete node;
                size--;
                reBalance(node_parent);
            }
            // node has only right son
            else if(!node->left) {
                if(!node_parent) {
                    root = node->right;
                    root->parent = nullptr;
                } else if(node_parent->left == node) {
                    node_parent->left = node->right;
                    node->right->parent = node_parent;
                } else {
                    node_parent->right = node->right;
                    node->right->parent = node_parent;
                }
                delete node;
                size--;
                reBalance(node_parent);
            }
            // has left and right sons
            // replace with the next greater key
            else {
                AVLTreeNode<Data, Key> *temp_node = node->right;
                while(temp_node->left != nullptr) {
                    temp_node = temp_node->left;
                }
                node->data = temp_node->data;
                node->key = temp_node->key;
                remove(temp_node);
            }
        }


    }

    void reBalance(AVLTreeNode<Data, Key> *node) {
        setBalance(node);
        if(node->balance == MAX_BALANCE) {
            if(getHeight(node->left->left) >= getHeight(node->left->right)) {
                node = rotateRight(node);
            } else {
                node = rotateLeftRight(node);
            }
        } else if(node->balance == MIN_BALANCE) {
            if(getHeight(node->right->right) >= getHeight(node->right->left)) {
                node = rotateLeft(node);
            } else {
                node = rotateRightLeft(node);
            }
        }
        if(node->parent != nullptr) {
            reBalance(node->parent);
        } else {
            root = node;
        }
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
    int treeSize() {
        return size;
    }

};

#endif //DATASTRUCTURES_AVL_H
