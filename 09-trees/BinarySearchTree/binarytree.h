/**
 * @file   binarytree.h
 * @author CS151 North Idaho College
 * @date   2020/10/12
 */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    // TreeNode() {}
    TreeNode(int data1=0, TreeNode *left1=nullptr, TreeNode *right1=nullptr)
    {
        data = data1;
        left = left1;
        right = right1;
    }
};


class BinaryTree
{
public:
    BinaryTree(); // 1
    ~BinaryTree(); // 9

    // Adding to the tree
    void insert(int newData); // 2
    void insertR(int newData); // 7

    // Removing an item from the tree
    void remove(int value); // 8

    // Searching for an item in the tree
    bool search(int value) const; // 4
    bool searchR(int value) const; // 6

    // Traversal techniques
    string toStringInOrder() const; // 3
    string toStringPreOrder() const; // 3
    string toStringPostOrder() const; // 3

    // Another traversal technique
    string toStringLevelOrder() const; // 5
    int height() const; // 5

private:
    TreeNode *mRoot;

    // helper functions
};

#endif