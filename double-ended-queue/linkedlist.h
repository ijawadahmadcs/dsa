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
    Node* tail;
    LinkedList();              
    void insertAtStart(int value);  // Insert at front
    void insertAtEnd(int value);  // Insert at rear
    void deleteAtStart();  // Delete from front
    void deleteFromEnd();  // Delete from rear
    int peekFront();  // View front element
    int peekRear();  // View rear element
    void insertAtPosition(int value, int position);  // Not allowed in deque
    void deleteAtPosition(int position);  // Not allowed in deque
    bool search(int value);
    int countNodes();
    void reverse();  // Not allowed in deque
    void concatenate(LinkedList& otherList);
    void split(int position, LinkedList& secondList);  // Not allowed in deque
    int findLargest();
    int findSmallest();
    int getSum();
    double getAverage();
    void display();  
    int findThirdLargest();      
};

#endif
