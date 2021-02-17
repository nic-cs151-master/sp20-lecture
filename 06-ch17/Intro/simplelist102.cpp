/**
 * @file simplelist102.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief Introduction to linked list. A very basic implementation.
 * @version 0.1
 * @date 2021-02-17
 * 
 */
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d=0, Node *p=nullptr)
    {
        data = d;
        next = p;
    }
};

void displayList(Node *nodePtr);
void addFrontV1(Node *ptr, int value);
void addFrontV2(Node *&ptr, int value);
void addFrontV3(Node **ptr, int value);

int main()
{
    // empty list
    Node *head = nullptr;

    // create first node
    head = new Node(5, head);
    // Node *newNode = new Node;
    // newNode->data = 5;
    // newNode->next = nullptr;
    // head = newNode;

    // create second node
    head = new Node(24, head);
    // newNode = new Node;
    // newNode->data = 24;
    // newNode->next = head;
    // head = newNode;

    head = new Node(3, head);
    // newNode = new Node;
    // newNode->data = 3;
    // newNode->next = head;
    // head = newNode;

    head = new Node(12, head);
    // newNode = new Node;
    // newNode->data = 12;
    // newNode->next = head;
    // head = newNode;

    // cout << "1st node's value: " << head->data << '\n';
    // cout << "2nd node's value: " << head->next->data << '\n';
    // cout << "3rd node's value: " << head->next->next->data << '\n';
    // cout << "4th node's value: " << head->next->next->next->data << '\n';
    // cout << endl;

    displayList(head);
    // Node *nodePtr = head;
    // while (nodePtr != nullptr)
    // {
    //     cout << nodePtr->data << ' ';
    //     nodePtr = nodePtr->next;
    // }

    addFrontV1(head, 15);
    addFrontV2(head, 15);
    addFrontV3(&head, 15);

    displayList(head);

    return 0;
}

void addFrontV1(Node *ptr, int value)
{
    ptr = new Node(value, ptr);
}

void addFrontV2(Node *&ptr, int value)
{
    ptr = new Node(value, ptr);
}

void addFrontV3(Node **ptr, int value)
{
    *ptr = new Node(value, *ptr);
}

void displayList(Node *nodePtr)
{
    while (nodePtr != nullptr)
    {
        cout << nodePtr->data << ' ';
        nodePtr = nodePtr->next;
    }
    cout << endl;
}