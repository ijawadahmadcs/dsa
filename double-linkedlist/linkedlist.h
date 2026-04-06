#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};


struct LinkedList {
    Node* head;
    LinkedList();              
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int position); 
    void deleteAtBeginning();
    void deleteFromEnd();
    void deleteAtPosition(int position); 
    void deleteByValue(int value);
    bool search(int value);
    int countNodes();
    void reverse(); 
    void concatenate(LinkedList& otherList);
    void split(int position, LinkedList& secondList);
    int findLargest();
    int findSmallest();
    int getSum();
    double getAverage();
    void display();  
    int findThirdLargest();      
};

#endif
