#include <iostream>
#include "linkedlist.h"
using namespace std;    

int main(){
    LinkedList list;

    list.insertAtBeginning(5);
    list.insertAtBeginning(4);
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);

    cout << "Before deleting 3: ";
    Node* temp = list.head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    list.deleteByValue(3);

    cout << "After deleting 3: ";
    temp = list.head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}