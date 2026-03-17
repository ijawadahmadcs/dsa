#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;  // Point to itself
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    
    if (head == NULL) {
        head = newNode;
        newNode->next = head;  // Point to itself
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
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

    for (int i = 1; temp->next != head && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp->next == head && position > countNodes() + 1) {
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

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* last = head;

    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;
    delete temp;
}

void LinkedList::deleteFromEnd() {

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != head) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = head;
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

    for (int i = 1; temp->next != head && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp->next == head) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}


bool LinkedList::search(int value) {

    if (head == NULL) {
        return false;
    }

    Node* temp = head;

    do {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    return false;
}
void LinkedList::searchAndReplace(int searchValue) {
    int newValue;
    cout << "Enter the new value: ";
    cin >> newValue;

    Node* temp = head;
    do {
        if (temp->data == searchValue) {
            temp->data = newValue;
        }
       temp=temp->next;
    
    } while (temp != head);
}

int LinkedList::countNodes() {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    Node* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}


void LinkedList::reverse() {

    if (head == NULL || head->next == head) {
        return;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    Node* last = head;

    // Find the last node
    while (last->next != head) {
        last = last->next;
    }

    prev = last;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head = prev;
}

void LinkedList::display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << head->data << endl;
}



void LinkedList::concatenate(LinkedList& otherList) {

    if (head == NULL) {
        head = otherList.head;
        return;
    }

    if (otherList.head == NULL) {
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    Node* otherLast = otherList.head;
    while (otherLast->next != otherList.head) {
        otherLast = otherLast->next;
    }

    temp->next = otherList.head;
    otherLast->next = head;
}



void LinkedList::split(int position, LinkedList& secondList) {

    if (position <= 0 || head == NULL)
        return;

    Node* temp = head;

    for (int i = 1; temp->next != head && i < position; i++) {
        temp = temp->next;
    }

    if (temp->next == head)
        return;

    secondList.head = temp->next;
    
    Node* secondLast = secondList.head;
    while (secondLast->next != head) {
        secondLast = secondLast->next;
    }

    secondLast->next = secondList.head;
    temp->next = head;
}



int LinkedList::findLargest() {

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }

    int largest = head->data;
    Node* temp = head->next;

    while (temp != head) {
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

    while (temp != head) {
        if (temp->data > first)
            first = temp->data;
        temp = temp->next;
    }


    second = -1;
    temp = head;

    do {
        if (temp->data < first) {
            second = temp->data;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    do {
        if (temp->data > second && temp->data < first)
            second = temp->data;
        temp = temp->next;
    } while (temp != head);

    // Step 3: Find third largest
    third = -1;
    temp = head;

    do {
        if (temp->data < second) {
            third = temp->data;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    do {
        if (temp->data > third && temp->data < second)
            third = temp->data;
        temp = temp->next;
    } while (temp != head);

    return third;
}

int LinkedList::findSmallest() {

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }

    int smallest = head->data;
    Node* temp = head->next;

    while (temp != head) {
        if (temp->data < smallest) {
            smallest = temp->data;
        }
        temp = temp->next;
    }

    return smallest;
}


int LinkedList::getSum() {

    if (head == NULL) {
        return 0;
    }

    int sum = 0;
    Node* temp = head;

    do {
        sum += temp->data;
        temp = temp->next;
    } while (temp != head);

    return sum;
}


double LinkedList::getAverage() {

    int totalNodes = countNodes();

    if (totalNodes == 0)
        return 0;

    int sum = getSum();

    return (double)sum / totalNodes;
}
