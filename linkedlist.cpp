/*********************
Name: Justin Rivas
Coding 05
Purpose: Building a doubly linked list.
**********************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){

}

void LinkedList::addHead(int id, string *data){
    Node *newNode = new Node();
    newNode->data.id = id;
    newNode->data.data = *data;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
}

bool LinkedList::addNode(int id, string *data){
    bool successfulAdd = false;
    if(id > 0 && *data != "\0"){
        Node *current = head;
        if(head == NULL || id < current->data.id){
            addHead(id, data);
            successfulAdd = true;
        } else{
            while(current->next != NULL && id >= current->next->data.id){
                current = current->next;
            }
            Node *newNode = new Node();
            newNode->data.id = id;
            newNode->data.data = *data;

            if(id == current->data.id){
                successfulAdd = false;
            } else{
                if(current->next == NULL){
                    current->next = newNode;
                    newNode->next = NULL;
                    newNode->prev = current;
                    successfulAdd = true;
                } else{
                    newNode->next = current->next;
                    current->next->prev = newNode;
                    current->next = newNode;
                    newNode->prev = current;
                    successfulAdd = true;
                }
            }
        }
    }
    return successfulAdd;
}


bool LinkedList::deleteNode(int){
    
}

bool LinkedList::getNode(int, Data*){
    
}

void LinkedList::printList(bool backwards){
    Node *current = head;
    if(backwards == false){
        while(current != NULL){
            cout << current->data.id << ":" << current->data.data << endl;
            current = current->next;
        }
    cout << endl;
    } else{
        current = head;
        bool tail = false;
        while(current!= NULL && !tail){
            if(current->next){
                current = current->next;
            } else{
                tail = true;
            }
        }
        while(current){
            cout << current->data.id << ": " << current->data.data << endl;
            current = current->prev;
        }
    }
}

int LinkedList::getCount(){
    
}

bool LinkedList::clearList(){
    
}

bool LinkedList::exists(int){
    
}