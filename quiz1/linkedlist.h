#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;


struct Node{
public:
    int data;   
    Node* next;
    Node* prev;
    Node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }

};

struct LinkedList{
public:
    Node* head;
    Node* next;
    LinkedList();
    void insertAtBeginning(int value);
    void deleteByValue(int value);
};

#endif