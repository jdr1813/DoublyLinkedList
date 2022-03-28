/*********************
Name: Justin Rivas
Coding 05
Purpose: Building a doubly linked list.
**********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "data.h"
#include <iostream>
#include <string> 

using std::cout;
using std::endl;

class LinkedList {

public:

    LinkedList();
    ~LinkedList();
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);
    
private:
    void addHead(int, string*);
    
    Node *head;
};

#endif //LINKED_LIST_H