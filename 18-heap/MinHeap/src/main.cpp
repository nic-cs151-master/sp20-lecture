#include <iostream>
#include "minheap.h"

int main()
{
    MinHeap hp;

    hp.insert(5);
    hp.insert(3);
    hp.insert(52);
    hp.insert(2);
    hp.insert(6);
    hp.insert(18);
    hp.insert(9);
    std::cout << hp.toString() << '\n';

    std::cout << hp.extractMin() << '\n';
    std::cout << hp.toString() << '\n';
    std::cout << hp.getMin() << '\n';
    
    return 0;
}