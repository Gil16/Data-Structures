#include <iostream>
#include "LinkedList.h"

int main() {
    auto *list = new LinkedList<int>();
    list->AddNode(1);
    list->AddNode(2);
    list->PrintList();
    list->RemoveNodeByIndex(0);
    list->PrintList();
    return 0;
}