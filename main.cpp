#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"

int main() {
    auto stack = new Stack<int>();
    stack->Push(1);
    stack->Push(2);
    stack->Push(3);
    stack->Push(4);
    stack->Push(5);

    std::cout << stack->Size();

    return 0;
}