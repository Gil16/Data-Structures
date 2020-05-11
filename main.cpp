#include <iostream>
#include "LinkedList.h"
#include "Queue.h"

int main() {
    auto *list = new LinkedList<int>();
    list->AddNode(1);
    list->AddNode(2);
    list->AddNode(3);
    list->AddNode(4);
    list->PrintList();

    std::cout << std::endl;

    auto *queue = new Queue<char*>();
    queue->Enqueue(const_cast<char *>("World"));
    queue->Enqueue(const_cast<char *>("Hello"));
    queue->PrintQueue();

    return 0;
}