#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
    next = NULL;
}


void LinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);

    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}


void LinkedList::deleteByValue(int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found!" << endl;
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    delete temp;
}