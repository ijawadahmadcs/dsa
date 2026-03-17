#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}

void LinkedList::insertAtStart(int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        cout << "Inserted " << value << " at front of deque.\n";
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    cout << "Inserted " << value << " at front of deque.\n";
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);

    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        cout << "Inserted " << value << " at rear of deque.\n";
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    cout << "Inserted " << value << " at rear of deque.\n";
}

void LinkedList::deleteAtStart() {
    if (head == NULL) {
        cout << "Deque is empty! Underflow\n";
        return;
    }

    Node* temp = head;
    cout << "Deleted " << head->data << " from front of deque.\n";

    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    delete temp;
}

void LinkedList::deleteFromEnd() {
    if (tail == NULL) {
        cout << "Deque is empty! Underflow\n";
        return;
    }

    Node* temp = tail;
    cout << "Deleted " << tail->data << " from rear of deque.\n";

    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    delete temp;
}

int LinkedList::peekFront() {
    if (head == NULL) {
        cout << "Deque is empty!\n";
        return -1;
    }
    return head->data;
}

int LinkedList::peekRear() {
    if (tail == NULL) {
        cout << "Deque is empty!\n";
        return -1;
    }
    return tail->data;
}

void LinkedList::insertAtPosition(int value, int position) {
    cout << "Not allowed in deque! Use insertAtStart or insertAtEnd instead.\n";
}

void LinkedList::deleteAtPosition(int position) {
    cout << "Not allowed in deque! Use deleteAtStart or deleteFromEnd instead.\n";
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

    if (head == NULL) {
        cout << "Deque is empty!\n";
        return;
    }

    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {

        // swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    // swap head and tail
    temp = head;
    head = tail;
    tail = temp;

    cout << "Deque reversed successfully.\n";
}

void LinkedList::display() {
    if (head == NULL) {
        cout << "Deque is empty!\n";
        return;
    }

    Node* temp = head;
    cout << "Deque (Front to Rear): ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void LinkedList::concatenate(LinkedList& otherList) {
    if (head == NULL) {
        head = otherList.head;
        tail = otherList.tail;
        cout << "Deque concatenated successfully.\n";
        return;
    }

    if (otherList.head == NULL) {
        cout << "Other deque is empty. Nothing to concatenate.\n";
        return;
    }

    tail->next = otherList.head;
    otherList.head->prev = tail;
    tail = otherList.tail;
    cout << "Deque concatenated successfully.\n";
}

void LinkedList::split(int position, LinkedList& secondList) {

    if (head == NULL) {
        cout << "Deque is empty!\n";
        return;
    }

    int total = countNodes();

    if (position <= 0 || position >= total) {
        cout << "Invalid split position!\n";
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position; i++) {
        temp = temp->next;
    }

    // second deque start
    secondList.head = temp->next;
    secondList.tail = tail;

    // break first deque
    temp->next = NULL;
    tail = temp;

    if (secondList.head != NULL)
        secondList.head->prev = NULL;

    cout << "Deque split successfully.\n";
}

int LinkedList::findLargest() {
    if (head == NULL) {
        cout << "Deque is empty!\n";
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
        cout << "Less than 3 elements!\n";
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
        cout << "Deque is empty!\n";
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
