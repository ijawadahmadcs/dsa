#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);  
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void LinkedList::insertAtPosition(int value, int position) {
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void LinkedList::deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteFromEnd() {

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}


void LinkedList::deleteAtPosition(int position) {
    if (head == NULL || position <= 0) {
        cout << "Invalid operation!" << endl;
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    Node* temp = head;

    for (int i = 1; temp->next != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}


bool LinkedList::search(int value) {

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

int LinkedList::countNodes() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}


void LinkedList::reverse() {

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;   
        prev = current;      
        current = next;       
    }

    head = prev;
}

void LinkedList::display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}



void LinkedList::concatenate(LinkedList& otherList) {

    if (head == NULL) {
        head = otherList.head;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = otherList.head;
}



void LinkedList::split(int position, LinkedList& secondList) {

    if (position <= 0 || head == NULL)
        return;

    Node* temp = head;

    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
        return;

    secondList.head = temp->next;
    temp->next = NULL;
}



int LinkedList::findLargest() {

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }

    int largest = head->data;
    Node* temp = head->next;

    while (temp != NULL) {
        if (temp->data > largest) {
            largest = temp->data;
        }
        temp = temp->next;
    }

    return largest;
}

int LinkedList::findThirdLargest() {

    if (countNodes() < 3) {
        cout << "Less than 3 elements!" << endl;
        return -1;
    }

    int first, second, third;
    Node* temp = head;

    first = head->data;
    temp = head->next;

    while (temp != NULL) {
        if (temp->data > first)
            first = temp->data;
        temp = temp->next;
    }


    second = -1;
    temp = head;

    while (temp != NULL) {
        if (temp->data < first) {
            second = temp->data;
            break;
        }
        temp = temp->next;
    }

    while (temp != NULL) {
        if (temp->data > second && temp->data < first)
            second = temp->data;
        temp = temp->next;
    }

    // Step 3: Find third largest
    third = -1;
    temp = head;

    while (temp != NULL) {
        if (temp->data < second) {
            third = temp->data;
            break;
        }
        temp = temp->next;
    }

    while (temp != NULL) {
        if (temp->data > third && temp->data < second)
            third = temp->data;
        temp = temp->next;
    }

    return third;
}

int LinkedList::findSmallest() {

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }

    int smallest = head->data;
    Node* temp = head->next;

    while (temp != NULL) {
        if (temp->data < smallest) {
            smallest = temp->data;
        }
        temp = temp->next;
    }

    return smallest;
}


int LinkedList::getSum() {

    int sum = 0;
    Node* temp = head;

    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }

    return sum;
}


double LinkedList::getAverage() {

    int totalNodes = countNodes();

    if (totalNodes == 0)
        return 0;

    int sum = getSum();

    return (double)sum / totalNodes;
}