/**
 * @file readNumbers.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief Introduction to linked list. A very basic implementation.
 * @version 0.1
 * @date 2021-02-17
 * 
 */
#include <iostream>
#include <fstream>
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
    // open the file
    fstream file("numbers.dat", ios::in);

    if (!file)
    {
        cerr << "Error opening file\n";
        exit(-1);
    }


    // empty list
    Node *head = nullptr;

    // read data from file and add to linked list
    int number;
    while (file >> number)
    {
        head = new Node(number, head);
    }

    // display linked list
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