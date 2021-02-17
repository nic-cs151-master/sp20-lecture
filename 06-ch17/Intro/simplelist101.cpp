/**
 * @file simplelist.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief 
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
void addToFrontV1(Node *ptr, int data);
void addToFrontV2(Node *&ptr, int data);
void addToFrontV3(Node **ptr, int data);

int main()
{
    // empty list
    Node *head = nullptr;

    head = new Node(5, head);
    // Node *newNode = new Node(5);
    // newNode->data = 5;
    // newNode->next = nullptr;
    // head = newNode;

    head = new Node(13, head);
    // newNode = new Node;
    // newNode->data = 13;
    // newNode->next = head;
    // head = newNode;

    head = new Node(24, head);
    // newNode = new Node;
    // newNode->data = 24;
    // newNode->next = head;
    // head = newNode;

    head = new Node(92, head);


    // cout << "1st node's value: " << head->data << '\n';
    // cout << "2nd node's value: " << head->next->data << '\n';
    // cout << "3rd node's value: " << head->next->next->data << '\n';
    // cout << "4th node's value: " << head->next->next->next->data << '\n';

    displayList(head);
    // Node *nodePtr = head;
    // while (nodePtr != nullptr)
    // {
    //     cout << nodePtr->data << '\n';
    //     nodePtr = nodePtr->next;
    // }

    // addToFrontV1(head, 15); // WILL NOT WORK
    addToFrontV2(head, 15);
    addToFrontV3(&head, 15);

    cout << "Final list: ";
    displayList(head);

    return 0;
}

void addToFrontV1(Node *ptr, int data)
{
    ptr = new Node(data, ptr);
}

void addToFrontV2(Node *&ptr, int data)
{
    ptr = new Node(data, ptr);
}

void addToFrontV3(Node **ptr, int data)
{
    *ptr = new Node(data, *ptr);
}

void displayList(Node *nodePtr)
{
    while (nodePtr != nullptr)
    {
        cout << nodePtr->data << ' ';
        nodePtr = nodePtr->next;
    }
    cout << '\n';
}