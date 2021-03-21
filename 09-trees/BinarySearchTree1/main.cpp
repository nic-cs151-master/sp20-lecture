/**
 * @file   main.cpp
 * @author CS151 North Idaho College
 * @date   2020/10/12
 * 
 */
#include <iostream>
#include "bst.h"

using std::cout;

int main()
{
    BinarySearchTree myTree;

    // Activity: Draw BST 
    // myTree.insert(12);
    // myTree.insert(10);
    // myTree.insert(11);
    // myTree.insert(26);
    // myTree.insert(28);
    // myTree.insert(18);
    // myTree.insert(19);
    // myTree.insert(6);
    myTree.insertR(50);
    myTree.insertR(30);
    myTree.insertR(70);
    myTree.insertR(20);
    myTree.insertR(40);
    myTree.insertR(60);
    myTree.insertR(80);
    myTree.insertR(55);
    myTree.insertR(65);
    myTree.insertR(90);
    myTree.insertR(59);
    myTree.insertR(85);
    myTree.insertR(95);
    myTree.insertR(75);
    myTree.insertR(72);

    // cout << "Height: " << myTree.height() << '\n';
    
    cout << "In order: " << myTree.toStringInOrder() << '\n';
    cout << "In order: " << myTree.toStringInOrderIt() << '\n';
    cout << "Post order: " << myTree.toStringPostOrder() << '\n';
    cout << "Pre order: " << myTree.toStringPreOrder() << '\n';
    cout << "Level order: " << myTree.toStringLevelOrder() << '\n';

    cout << "search for 85: " << myTree.search(85) << '\n';
    // cout << "searchR for 85: " << myTree.searchR(85) << '\n';
    cout << "search for 25: " << myTree.search(25) << '\n';
    // cout << "searchR for 25: " << myTree.searchR(25) << '\n';

    myTree.remove(20);
    myTree.remove(55);
    myTree.remove(50);
    myTree.remove(70);
    cout << "In order: " << myTree.toStringInOrder() << '\n';
    cout << "Post order: " << myTree.toStringPostOrder() << '\n';
    cout << "Pre order: " << myTree.toStringPreOrder() << '\n';

    return 0;
}

    // myTree.insertR("John");
    // myTree.insertR("Kevin");
    // myTree.insertR("Jim");
    // myTree.insertR("Paul");
    // myTree.insertR("Maria");
    // cout << "In order: " << myTree.toStringInOrder() << '\n';