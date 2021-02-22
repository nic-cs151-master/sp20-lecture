#include <iostream>
#include "linkedlist.h"
#include "sortedlinkedlist.h"
using namespace std;

int main()
{
    SortedLinkedList list;

    list.add(234.23);
    list.add(24.34);
    list.add(565.23);
    list.add(452.645);
    list.add(3);
    list.add(546.2);

    cout << list.toString() << '\n';
    cout << list.toStringR() << '\n';

    list.remove(234.23);
    list.remove(565.23);

    cout << list.toString() << '\n';

    return 0;
}