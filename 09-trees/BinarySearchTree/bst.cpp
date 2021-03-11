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

string BinarySearchTree::toStringPreOrder() const
{
    ostringstream ostr("");
    toStringPreOrder(mRoot, ostr);
    return ostr.str();
}

void BinarySearchTree::toStringPreOrder(TreeNode *ptr, ostringstream &ostr) const
{
    // base case
    if (ptr == nullptr)
    {
        return;
    }
    else
    {
        ostr << ptr->data << ' '; // process data
        toStringPreOrder(ptr->left, ostr);
        toStringPreOrder(ptr->right, ostr);
    }
}

string BinarySearchTree::toStringPostOrder() const
{
    ostringstream ostr("");
    toStringPostOrder(mRoot, ostr);
    return ostr.str();
}

void BinarySearchTree::toStringPostOrder(TreeNode *ptr, ostringstream &ostr) const
{
    // base case
    if (ptr == nullptr)
    {
        return;
    }
    else
    {
        toStringPostOrder(ptr->left, ostr);
        toStringPostOrder(ptr->right, ostr);
        ostr << ptr->data << ' '; // process data
    }
}

string BinarySearchTree::toStringLevelOrder() const
{
    ostringstream ostr("");

    for (int h = 0; h < height(); ++h)
    {
        toStringLevelOrder(mRoot, ostr, h);
    }

    return ostr.str();
}

void BinarySearchTree::toStringLevelOrder(TreeNode *ptr, ostringstream &ostr, int level) const
{
    // base case
    if (ptr == nullptr)
    {
        return;
    }
    else if (level == 0)
    {
        ostr << ptr->data << ' ';
        return;
    }
    else
    {
        toStringLevelOrder(ptr->left, ostr, level-1);
        toStringLevelOrder(ptr->right, ostr, level-1);
    }
    // else
    // {
    //     toStringPostOrder(ptr->left, ostr);
    //     toStringPostOrder(ptr->right, ostr);
    //     ostr << ptr->data << ' '; // process data
    // }
}

bool BinarySearchTree::search(int value) const
{
    // tree is empty
    if (mRoot == nullptr)
    {
        return false;
    }
    else
    {
        TreeNode *ptr = mRoot;

        while (ptr != nullptr)
        {
            // found the value
            if (ptr->data == value)
            {
                return true;
            }
            // go left or go right???
            else if (ptr->data < value)
            {
                ptr = ptr->right;
            }
            else
            {
                ptr = ptr->left;
            }
        }
    }

    return false;
}


int BinarySearchTree::height() const
{
    return height(mRoot);
}

int BinarySearchTree::height(TreeNode *ptr) const
{
    if (ptr == nullptr)
    {
        return 0;
    }
    else
    {
        return std::max(height(ptr->left), height(ptr->right)) + 1;
    }
}

void BinarySearchTree::remove(int value)
{
    removeR(mRoot, value);
}

void BinarySearchTree::removeR(TreeNode *&ptr, int value)
{
    // tree is empty
    if (ptr == nullptr)
    {
        return;
    }
    else if (value < ptr->data)
    {
        removeR(ptr->left, value);
    }
    else if (value > ptr->data)
    {
        removeR(ptr->right, value);
    }
    else
    {
        deleteNode(ptr);
    }
}

void BinarySearchTree::deleteNode(TreeNode *&nodePtr)
{
    // 1st case: leaf node
    if (isLeaf(nodePtr))
    {
        delete nodePtr;
        nodePtr = nullptr;
    }
    // 2nd case: one child on the left
    else if (nodePtr->right == nullptr)
    {
        TreeNode *temp = nodePtr;
        nodePtr = nodePtr->left;
        temp->left = nullptr;
        delete temp;
        temp = nullptr;
    }
    // 2nd case: one child on the right
    else if (nodePtr->left == nullptr)
    {
        TreeNode *temp = nodePtr;
        nodePtr = nodePtr->right;
        temp->right = nullptr;
        delete temp;
        temp = nullptr;
    }
    // 3rd case: two children
    else
    {
        int successorValue = processInOrderSuccessor(nodePtr->right);
        nodePtr->data = successorValue;
    }
}


int BinarySearchTree::processInOrderSuccessor(TreeNode *&ptr) const
{
    if (ptr->left != nullptr)
    {
        return processInOrderSuccessor(ptr->left);
    }
    else
    
    {
        int successorValue = ptr->data;

        // leaf node
        if (isLeaf(ptr))
        {
            delete ptr;
            ptr = nullptr;
        }
        /// right child
        else
        {
            TreeNode *temp = ptr;
            ptr = ptr->right;
            temp->right = nullptr;
            delete temp;
            temp = nullptr;
        }

        return successorValue;
    }
}


bool BinarySearchTree::isLeaf(TreeNode *ptr) const
{
    return ptr->left == nullptr && ptr->right == nullptr;
}