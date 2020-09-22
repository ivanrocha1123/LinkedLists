//
//  LinkedList.h
//  DataStructs&Algo
//
//  Created by Ivan Rocha on 9/17/20.
//  Copyright © 2020 Ivan Rocha. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

using namespace std;

struct ListNode
{
    int value;
    struct ListNode *next;
};

class LinkedList
{
private:
    ListNode listNode;
    ListNode *head;
    
public:
    
    // Constructor.
    LinkedList()
    {head = nullptr;}
    
    // Destructor.
    ~LinkedList();
    
    // Linked List Operations.
    int size();
    void appendNode(int);
    void insertNode(int, int);
    void deleteNode(int);
    void displayList(ListNode*);
    void displayBackward(ListNode*);
    void reverseList(ListNode*);
    ListNode* getHead();
};

LinkedList::~LinkedList()
{
    ListNode *nodePtr; // To traverse the list.
    ListNode *nextNode; // To point to the next node.
    
    // Position nodePtr at the head of the list.
    nodePtr = head;
    
    // While nodePtr is not at the end of the list.
    while(nodePtr != nullptr)
    {
        // Save the pointer to the next node.
        nextNode = nodePtr->next;
        
        // Delete the current node.
        delete nodePtr;
        
        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}

int LinkedList::size()
{
    ListNode *nodePtr;
    nodePtr = head;
    
    int size = 0;
    
    while(nodePtr)
    {
        size++;
        nodePtr = nodePtr -> next;
    }
    
    return size;
}

void LinkedList::appendNode(int num)
{
    ListNode *newNode; // To point at newly constructed node.
    ListNode *nodePtr; // Iterate through the linked list.
    
    newNode = new ListNode; // Create the node that will be inserted.
    newNode -> value = num; // Set value to num.
    newNode -> next = nullptr; // Set the next member to nullptr.
    
    if(!head)
        head = newNode;
    else
    {
        // Initialize nodePtr to head.
        nodePtr = head;
        
        // Find the last node in the list.
        while(nodePtr -> next)
            nodePtr = nodePtr -> next;
        
        // Once found, make the last node point to the newNode.
        nodePtr -> next = newNode;
    }
}

void LinkedList::insertNode(int num, int pos)
{
    int listSize = size();
    
    if(pos < 0 || pos > listSize)
        return;
    else
    {
        ListNode *nodePtr;
        ListNode *previousNode;
        ListNode *newNode;
        
        newNode = new ListNode;
        newNode -> value = num;
        
        nodePtr = head;
        previousNode = nullptr;
        
        if(!head)
        {
            head = newNode;
            newNode -> next = nullptr;
        }
        else
        {
            for(int i = 0; i < pos; i++)
            {
                previousNode = nodePtr;
                nodePtr = nodePtr -> next;
            }
            
            if(previousNode == nullptr)
            {
                head = newNode;
                newNode -> next = nodePtr;
            }
            else
            {
                previousNode -> next = newNode;
                newNode -> next = nodePtr;
            }
        }
    }
}

void LinkedList::deleteNode(int pos)
{
    int listSize = size();
    
    if(pos < 0 || pos > listSize)
        return;
    else
    {
        ListNode *nodePtr;
        ListNode *previousNode;
        
        if(!head)
            return;
        
        if(pos == 0)
        {
            nodePtr = head -> next;
            delete head;
            head = nodePtr;
        }
        else
        {
            nodePtr = head;
            previousNode = nullptr;
            
            for(int i = 0; i < pos; i++)
            {
                previousNode = nodePtr;
                nodePtr = nodePtr -> next;
            }
            
            if(nodePtr)
            {
                previousNode -> next = nodePtr -> next;
                delete nodePtr;
            }
        }
    }
}

void LinkedList::displayList(ListNode* nodePtr)
{
    if(nodePtr == nullptr)
        return;
    else
    {
        cout << nodePtr -> value << " ";
        displayList(nodePtr -> next);
    }
}

void LinkedList::displayBackward(ListNode* nodePtr)
{
    if(nodePtr == nullptr)
        return;
    else
    {
        displayBackward(nodePtr -> next);
        cout << nodePtr -> value << " ";
    }
}

void LinkedList::reverseList(ListNode *nodePtr)
{
    if(nodePtr -> next == nullptr)
    {
        head = nodePtr;
        return;
    }
    
    reverseList(nodePtr -> next);
    ListNode *previousNode;
    previousNode = nodePtr -> next;
    previousNode -> next = nodePtr;
    nodePtr -> next = nullptr;
}

ListNode* LinkedList::getHead()
{
    return head;
}


#endif /* LinkedList_h */
