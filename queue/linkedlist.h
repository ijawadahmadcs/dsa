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
    void insertAtEnd(int value);  // Enqueue (insert at rear)
    void deleteAtStart();  // Dequeue (delete from front)
    int peek();  // View front element
    void insertAtStart(int value);  // Not allowed in queue
    void insertAtPosition(int value, int position);  // Not allowed in queue
    void deleteFromEnd();  // Not allowed in queue
    void deleteAtPosition(int position);  // Not allowed in queue
    bool search(int value);
    int countNodes();
    void reverse();  // Not allowed in queue
    void concatenate(LinkedList& otherList);
    void split(int position, LinkedList& secondList);  // Not allowed in queue
    int findLargest();
    int findSmallest();
    int getSum();
    double getAverage();
    void display();  
    int findThirdLargest();      
};

#endif
