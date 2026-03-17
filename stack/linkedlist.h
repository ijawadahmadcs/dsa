#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};


struct LinkedList {
    Node* head;
    LinkedList();              
    void insertAtStart(int value);  // Insert at beginning (insertAtStart)
    void deleteAtStart();  // Delete at beginning (deleteAtStart)
    int peek();  // View top element
    void insertAtEnd(int value);  // Not allowed in stack
    void insertAtPosition(int value, int position);  // Not allowed in stack
    void deleteFromEnd();  // Not allowed in stack
    void deleteAtPosition(int position);  // Not allowed in stack
    bool search(int value);
    int countNodes();
    void reverse();  // Not allowed in stack
    void concatenate(LinkedList& otherList);
    void split(int position, LinkedList& secondList);  // Not allowed in stack
    int findLargest();
    int findSmallest();
    int getSum();
    double getAverage();
    void display();  
    int findThirdLargest();      
};

#endif
