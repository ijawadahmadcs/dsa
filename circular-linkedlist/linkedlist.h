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
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int position); 
    void deleteAtBeginning();
    void deleteFromEnd();
    void deleteAtPosition(int position); 
    bool search(int value);
    void searchAndReplace(int searchValue);
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
