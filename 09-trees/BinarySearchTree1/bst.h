/**
 * @file   bst.h
 * @author CS151 North Idaho College
 * @date   2020/10/12
 * 
 */
#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using std::string;
using std::ostringstream;


struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data1=0, TreeNode *left1=nullptr, TreeNode *right1=nullptr)
    {
        data = data1;
        left = left1;
        right = right1;
    }
};

typedef TreeNode* TreeNodePtr;

class BinarySearchTree
{
public:
    BinarySearchTree(); // DONE
    ~BinarySearchTree(); // 9

    // Adding to the tree
    void insert(int newData); // DONE
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

    string toStringInOrderIt() const;

    // Another traversal technique
    string toStringLevelOrder() const; // 5
    int height() const; // 5

private:
    TreeNodePtr mRoot;

    // helper functions
    void toStringInOrder(TreeNode *ptr, ostringstream &ostr) const;
    void toStringPreOrder(TreeNode *ptr, ostringstream &ostr) const;
    void toStringPostOrder(TreeNode *ptr, ostringstream &ostr) const;
    void toStringLevelOrder(TreeNode *ptr, ostringstream &ostr, int level) const;

    int height(TreeNode *ptr) const;

    bool isLeaf(TreeNode *ptr) const;
    void removeR(TreeNodePtr &ptr, int value);
    void deleteNode(TreeNodePtr &nodePtr);
    int processInOrderSuccessor(TreeNodePtr &ptr) const;

    void insertR(TreeNode *&ptr, int newData);

};

#endif