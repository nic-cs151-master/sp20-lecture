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

string BinarySearchTree::toStringPreOrder() const
{
    ostringstream ostr("");
    toStringPreOrder(mRoot, ostr);
    return ostr.str();
}


void BinarySearchTree::toStringPreOrder(TreeNode *ptr, ostringstream &ostr) const
{
    // simplest case
    if (ptr == nullptr)
    {
        return;
    }
    else
    {
        // process data
        ostr << ptr->data << ' ';
        // to left
        toStringPreOrder(ptr->left, ostr);
        // to right
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
    // simplest case
    if (ptr == nullptr)
    {
        return;
    }
    else
    {
        // to left
        toStringPostOrder(ptr->left, ostr);
        // to right
        toStringPostOrder(ptr->right, ostr);
        // process data
        ostr << ptr->data << ' ';
    }
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
            // found?
            if (ptr->data == value)
            {
                return true;
            }
            // left or right?
            else if (value < ptr->data)
            {
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }
    }

    return false;
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
        toStringLevelOrder(ptr->left, ostr, level - 1);
        toStringLevelOrder(ptr->right, ostr, level - 1);
    }
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
    // base case
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
        // found it
        deleteNode(ptr, value);
    }
}

void BinarySearchTree::deleteNode(TreeNode *&nodePtr, int value)
{
    // 1. leaf node
    if (isLeaf(nodePtr))
    {
        delete nodePtr;
        nodePtr = nullptr;
    }
    // 2. one child left
    else if (nodePtr->right == nullptr)
    {
        TreeNode *temp = nodePtr;
        nodePtr = nodePtr->left;
        temp->left = nullptr;
        delete temp;
        temp = nullptr;
    }
    // 2. one child right
    else if (nodePtr->left == nullptr)
    {
        TreeNode *temp = nodePtr;
        nodePtr = nodePtr->right;
        temp->right = nullptr;
        delete temp;
        temp = nullptr;
    }
    // 3. two children
    else
    {
        int successorValue = processInOrderSuccessor(nodePtr->right);
        nodePtr->data = successorValue;
    }
}

int BinarySearchTree::processInOrderSuccessor(TreeNode *&ptr)
{
    if (ptr->left != nullptr)
    {
        return processInOrderSuccessor(ptr->left);
    }
    else
    {
        // found successor value
        int successor = ptr->data;

        if (isLeaf(ptr))
        {
            delete ptr;
            ptr = nullptr;
        }
        else // right child
        {
            TreeNode *temp = ptr;
            ptr = ptr->right;
            temp->right = nullptr;
            delete temp;
            temp = nullptr;
        }

        return successor;
    }
}

bool BinarySearchTree::isLeaf(TreeNode *ptr) const
{
    return (ptr->left == nullptr) && (ptr->right == nullptr);
}