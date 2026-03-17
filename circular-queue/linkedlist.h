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
    Node* front;
    Node* rear;
    LinkedList();              
    void enqueue(int value);  // Insert at rear
    void dequeue();  // Delete from front
    int peek();  // View front element
    void insertAtStart(int value);  // Not allowed in circular queue
    void insertAtPosition(int value, int position);  // Not allowed in circular queue
    void deleteFromEnd();  // Not allowed in circular queue
    void deleteAtPosition(int position);  // Not allowed in circular queue
    bool search(int value);
    int countNodes();
    void reverse();  // Not allowed in circular queue
    void concatenate(LinkedList& otherList);
    void split(int position, LinkedList& secondList);  // Not allowed in circular queue
    int findLargest();
    int findSmallest();
    int getSum();
    double getAverage();
    void display();  
    int findThirdLargest();      
};

#endif
