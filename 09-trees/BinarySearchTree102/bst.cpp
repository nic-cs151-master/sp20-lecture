/**@file   bst.cpp
 * @author CS151 North Idaho College
 * @date   2020/10/12
 */
#include "bst.h"


BinarySearchTree::BinarySearchTree()
{
    // initializing
    mRoot = nullptr; // empty tree
}

BinarySearchTree::~BinarySearchTree()
{

}

void BinarySearchTree::insert(int newData)
{
    // case 1: tree empty
    if (mRoot == nullptr)
    {
        mRoot = new TreeNode(newData);
    }
    // case 2: tree not empty
    else
    {
        // find the correct location
        TreeNode *prevPtr = mRoot;
        TreeNode *ptr = mRoot;

        while (ptr != nullptr)
        {
            prevPtr = ptr;
            // case
            if (ptr->data == newData)
            {
                return;
            }
            // go left
            else if (ptr->data > newData)
            {
                ptr = ptr->left;
            }
            else // go right
            {
                ptr = ptr->right;
            }
        }

        // add new node to left
        if (prevPtr->data > newData)
        {
            prevPtr->left = new TreeNode(newData);
        }
        else // to the right
        {
            prevPtr->right = new TreeNode(newData);
        }
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
    // simplest case
    if (ptr == nullptr)
    {
        return;
    }
    else
    {
        // to left
        toStringInOrder(ptr->left, ostr);
        // process data
        ostr << ptr->data << ' ';
        // to right
        toStringInOrder(ptr->right, ostr);
    }
}