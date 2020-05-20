#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "AVL.h"
#include "Heap.h"

#include <assert.h>

using namespace std;


class TreeTest{
public:
    void insertTest(){
        AVLTree<double,int> tree = AVLTree<double ,int>();
        int *firstKey = new int(1);
        int *secondKey = new int(2);
        int *thirdKey = new int(3);
        int *fourthKey = new int(4);
        int *fifthKey = new int(5);
        int *sixthKey = new int(6);
        double *firstData = new double(1.1);
        double *secondData = new double(2.2);
        double *thirdData = new double(3.3);
        double *fourthData = new double(4.4);
        double *fifthData = new double(5.5);
        double *sixthData = new double(6.6);
        tree.insert(firstData,firstKey);
        assert(tree.treeSize() == 1);
        tree.insert(secondData,secondKey);
        tree.insert(thirdData,thirdKey);
        tree.insert(fourthData,fourthKey);
        tree.insert(fifthData,fifthKey);
        tree.insert(sixthData,sixthKey);
        assert(tree.treeSize() == 6);
    }

    void isExistTest(){
        AVLTree<double,int> tree = AVLTree<double ,int>();
        int *firstKey = new int(1);
        int *secondKey = new int(2);
        int *thirdKey = new int(3);
        double *firstData = new double(1.1);
        double *secondData = new double(2.2);
        double *thirdData = new double(3.3);
        int *toSearchKey = new int(3);
        tree.insert(firstData,firstKey);
        tree.insert(secondData,secondKey);
        tree.insert(thirdData,thirdKey);
        assert(tree.isKeyExists(toSearchKey));
        delete toSearchKey;
    }

    void sanityTest(){
        AVLTree<double,int> tree = AVLTree<double ,int>();
        int *firstKey = new int(1);
        int *secondKey = new int(2);
        int *thirdKey = new int(3);
        double *firstData = new double(1.1);
        double *secondData = new double(2.2);
        double *thirdData = new double(3.3);
        tree.insert(firstData,firstKey);
        tree.insert(secondData,secondKey);
        tree.insert(thirdData,thirdKey);
        assert(*(tree.getRoot()->key) == *secondKey);
        assert(*(tree.getRoot()->right->key) == *thirdKey);
        assert(*(tree.getRoot()->left->key) == *firstKey);
    }

    void heightTest(){
        AVLTree<double,int> tree = AVLTree<double ,int>();
        int *firstKey = new int(1);
        int *secondKey = new int(2);
        int *thirdKey = new int(3);
        double *firstData = new double(1.1);
        double *secondData = new double(2.2);
        double *thirdData = new double(3.3);
        tree.insert(firstData,firstKey);
        tree.insert(secondData,secondKey);
        tree.insert(thirdData,thirdKey);
        assert(tree.getHeight(tree.getRoot()) == 1);
        AVLTree<double,int> emptyTree = AVLTree<double ,int>();
        assert(emptyTree.getHeight(emptyTree.getRoot())==-1);
    }

    void removeTest(){
        AVLTree<double,int> tree = AVLTree<double ,int>();
        int *firstKey = new int(1);
        int *secondKey = new int(2);
        int *thirdKey = new int(3);
        double *firstData = new double(1.1);
        double *secondData = new double(2.2);
        double *thirdData = new double(3.3);
        tree.insert(firstData,firstKey);
        tree.insert(secondData,secondKey);
        tree.insert(thirdData,thirdKey);

        AVLTreeNode<double, int>* ok = nullptr;
        ok = tree.find(new int(2));
        tree.remove(ok);
        assert(tree.treeSize() == 2);
        assert(tree.getRoot()->balance != 0);
    }

    void AVLTests() {
        heightTest();
        insertTest();
        isExistTest();
        removeTest();
        sanityTest();
    }
};


int main(){
 //   TreeTest *t=new TreeTest();
 //   t->AVLTests();
 //   delete t;

    int length = 10;
    int arr[length] = {10, 17, 3, 4, 6, 0, 2, 12, 5, 8};
    MinHeap<int>* heap = new MinHeap<int>(arr, length);

    while(true) {
        if(heap->getNumElements() == 0) {
            break;
        }
        cout << heap->getMin() << endl;
        heap->deleteMin();
    }

    return 0;
}



