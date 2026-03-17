#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        cout << "Enqueued " << value << " into queue.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    cout << "Enqueued " << value << " into queue.\n";
}

void LinkedList::deleteAtStart() {
    if (head == NULL) {
        cout << "Queue is empty! Underflow\n";
        return;
    }

    Node* temp = head;
    cout << "Dequeued " << head->data << " from queue.\n";
    head = head->next;
    delete temp;
}

int LinkedList::peek() {
    if (head == NULL) {
        cout << "Queue is empty!\n";
        return -1;
    }
    return head->data;
}

void LinkedList::insertAtStart(int value) {
    cout << "Not allowed in queue! FIFO violation\n";
}

void LinkedList::insertAtPosition(int value, int position) {
    cout << "Not allowed in queue! FIFO violation\n";
}

void LinkedList::deleteFromEnd() {
    cout << "Not allowed in queue! FIFO violation\n";
}

void LinkedList::deleteAtPosition(int position) {
    cout << "Not allowed in queue! FIFO violation\n";
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
        cout << "Queue is empty!\n";
        return;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;   // store next node
        current->next = prev;   // reverse pointer
        prev = current;         // move prev forward
        current = next;         // move current forward
    }

    head = prev;

    cout << "Queue reversed successfully.\n";
}

void LinkedList::display() {
    if (head == NULL) {
        cout << "Queue is empty!\n";
        return;
    }

    Node* temp = head;
    cout << "Queue (Front to Rear): ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void LinkedList::concatenate(LinkedList& otherList) {
    if (head == NULL) {
        head = otherList.head;
        cout << "Queue concatenated successfully.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = otherList.head;
    cout << "Queue concatenated successfully.\n";
}

void LinkedList::split(int position, LinkedList& secondList) {

    if (head == NULL) {
        cout << "Queue is empty!\n";
        return;
    }

    if (position <= 0) {
        cout << "Invalid position!\n";
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position exceeds queue size!\n";
        return;
    }

    secondList.head = temp->next;
    temp->next = NULL;

    cout << "Queue split successfully.\n";
}

int LinkedList::findLargest() {
    if (head == NULL) {
        cout << "Queue is empty!\n";
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
        cout << "Queue is empty!\n";
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
