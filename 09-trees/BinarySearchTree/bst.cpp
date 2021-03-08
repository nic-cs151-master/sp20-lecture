/**@file   bst.cpp
 * @author CS151 North Idaho College
 * @date   2020/10/12
 */
#include "bst.h"


BinarySearchTree::BinarySearchTree()
{
    // initialize
    mRoot = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    // TODO
}

void BinarySearchTree::insert(int newData)
{
    // case 1: tree is empty
    if (mRoot == nullptr)
    {
        mRoot = new TreeNode(newData);
    }
    // case 2: not emtpy
    else
    {
        TreeNode *prevPtr = nullptr;
        TreeNode *ptr = mRoot;

        while (ptr != nullptr)
        {
            prevPtr = ptr;
            // data exist
            if (ptr->data == newData)
            {
                return;
            }
            // go left
            else if (ptr->data > newData)
            {
                ptr = ptr->left;
            }
            // go right
            else
            {
                ptr = ptr->right;
            }
        }

        if (prevPtr->data > newData)
        {
            prevPtr->left = new TreeNode(newData);
        }
        else
        {
            prevPtr->right = new TreeNode(newData);
        }
    }
}

void BinarySearchTree::insertV2(int newData)
{
    // case 1: tree is empty
    if (mRoot == nullptr)
    {
        mRoot = new TreeNode(newData);
    }
    // case 2: not emtpy
    else
    {
        TreeNode **ptr = &mRoot;

        while (*ptr != nullptr)
        {
            // data exist
            if ((*ptr)->data == newData)
            {
                return;
            }
            // go left
            else if ((*ptr)->data > newData)
            {
                ptr = &(*ptr)->left;
            }
            // go right
            else
            {
                ptr = &(*ptr)->right;
            }
        }

        *ptr = new TreeNode(newData);
    }
}

string BinarySearchTree::toStringInOrder() const
{
    ostringstream ostr("");
    toStringInOrder(mRoot, ostr);
    return ostr.str();
}

void BinarySearchTree::toStringInOrder(TreeNode *ptr, ostringstream &ostr) const
{
    // base case
    if (ptr == nullptr)
    {
        return;
    }
    else
    {
        toStringInOrder(ptr->left, ostr);
        ostr << ptr->data << ' '; // process data
        toStringInOrder(ptr->right, ostr);
    }
}
