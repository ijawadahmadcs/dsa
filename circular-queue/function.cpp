#include "linkedlist.h"

LinkedList::LinkedList() {
    front = NULL;
    rear = NULL;
}

void LinkedList::enqueue(int value) {
    Node* newNode = new Node(value);

    if (front == NULL) {
        front = newNode;
        rear = newNode;
        rear->next = front;  // circular link
        cout << "Enqueued " << value << " into circular queue.\n";
        return;
    }

    rear->next = newNode;
    rear = newNode;
    rear->next = front;  // maintain circular link
    cout << "Enqueued " << value << " into circular queue.\n";
}

void LinkedList::dequeue() {
    if (front == NULL) {
        cout << "Circular Queue is empty! Underflow\n";
        return;
    }

    if (front == rear) {
        // only one node
        cout << "Dequeued " << front->data << " from circular queue.\n";
        delete front;
        front = NULL;
        rear = NULL;
        return;
    }

    Node* temp = front;
    cout << "Dequeued " << front->data << " from circular queue.\n";
    front = front->next;
    rear->next = front;  // maintain circular link
    delete temp;
}

int LinkedList::peek() {
    if (front == NULL) {
        cout << "Circular Queue is empty!\n";
        return -1;
    }
    return front->data;
}

void LinkedList::insertAtStart(int value) {
    cout << "Not allowed in circular queue! Use enqueue instead.\n";
}

void LinkedList::insertAtPosition(int value, int position) {
    cout << "Not allowed in circular queue! Use enqueue instead.\n";
}

void LinkedList::deleteFromEnd() {
    cout << "Not allowed in circular queue! Use dequeue instead.\n";
}

void LinkedList::deleteAtPosition(int position) {
    cout << "Not allowed in circular queue! Use dequeue instead.\n";
}

bool LinkedList::search(int value) {
    if (front == NULL)
        return false;

    Node* temp = front;
    do {
        if (temp->data == value)
            return true;
        temp = temp->next;
    } while (temp != front);

    return false;
}

int LinkedList::countNodes() {
    if (front == NULL)
        return 0;

    int count = 0;
    Node* temp = front;
    do {
        count++;
        temp = temp->next;
    } while (temp != front);

    return count;
}

void LinkedList::reverse() {
    if (front == NULL || front == rear) {
        cout << "Circular Queue reversed successfully.\n";
        return;
    }

    Node* prev = rear;
    Node* current = front;
    Node* next = NULL;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != front);

    // swap front and rear
    Node* temp = front;
    front = rear;
    rear = temp;

    cout << "Circular Queue reversed successfully.\n";
}

void LinkedList::display() {
    if (front == NULL) {
        cout << "Circular Queue is empty!\n";
        return;
    }

    Node* temp = front;
    cout << "Circular Queue (Front to Rear): ";

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != front);

    cout << "(back to front)" << endl;
}

void LinkedList::concatenate(LinkedList& otherList) {
    if (front == NULL) {
        front = otherList.front;
        rear = otherList.rear;
        if (rear != NULL)
            rear->next = front;
        cout << "Circular Queue concatenated successfully.\n";
        return;
    }

    if (otherList.front == NULL) {
        cout << "Other queue is empty. Nothing to concatenate.\n";
        return;
    }

    rear->next = otherList.front;
    rear = otherList.rear;
    rear->next = front;  // maintain circular link
    cout << "Circular Queue concatenated successfully.\n";
}

void LinkedList::split(int position, LinkedList& secondList) {

    if (front == NULL) {
        cout << "Circular Queue is empty!\n";
        return;
    }

    int total = countNodes();

    if (position <= 0 || position >= total) {
        cout << "Invalid split position!\n";
        return;
    }

    Node* temp = front;

    for (int i = 1; i < position; i++) {
        temp = temp->next;
    }

    // second queue start
    secondList.front = temp->next;
    secondList.rear = rear;

    // first queue rear
    rear = temp;

    // fix circular links
    rear->next = front;
    secondList.rear->next = secondList.front;

    cout << "Circular Queue split successfully.\n";
}

int LinkedList::findLargest() {
    if (front == NULL) {
        cout << "Circular Queue is empty!\n";
        return -1;
    }

    int largest = front->data;
    Node* temp = front->next;

    while (temp != front) {
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
    Node* temp = front;

    first = front->data;
    temp = front->next;

    while (temp != front) {
        if (temp->data > first)
            first = temp->data;
        temp = temp->next;
    }

    second = -1;
    temp = front;

    do {
        if (temp->data < first) {
            second = temp->data;
            break;
        }
        temp = temp->next;
    } while (temp != front);

    while (temp != front) {
        if (temp->data > second && temp->data < first)
            second = temp->data;
        temp = temp->next;
    }

    third = -1;
    temp = front;

    do {
        if (temp->data < second) {
            third = temp->data;
            break;
        }
        temp = temp->next;
    } while (temp != front);

    while (temp != front) {
        if (temp->data > third && temp->data < second)
            third = temp->data;
        temp = temp->next;
    }

    return third;
}

int LinkedList::findSmallest() {
    if (front == NULL) {
        cout << "Circular Queue is empty!\n";
        return -1;
    }

    int smallest = front->data;
    Node* temp = front->next;

    while (temp != front) {
        if (temp->data < smallest) {
            smallest = temp->data;
        }
        temp = temp->next;
    }

    return smallest;
}

int LinkedList::getSum() {
    if (front == NULL)
        return 0;

    int sum = 0;
    Node* temp = front;

    do {
        sum += temp->data;
        temp = temp->next;
    } while (temp != front);

    return sum;
}

double LinkedList::getAverage() {
    int totalNodes = countNodes();

    if (totalNodes == 0)
        return 0;

    int sum = getSum();

    return (double)sum / totalNodes;
}
