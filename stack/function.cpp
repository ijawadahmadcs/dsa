#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::insertAtStart(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;  //current ka top ko point karega
    head = newNode;
    cout << "push " << value << " onto stack\n";
}

void LinkedList::deleteAtStart() {
    if (head == NULL) {
        cout << "Stack is empty! Underflow\n";     //underflow error
        return;
    }

    Node* temp = head;
    cout << "Popped " << head->data << " from stack.\n";
    head = head->next;
    delete temp;
}

int LinkedList::peek() {
    if (head == NULL) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return head->data;
}

void LinkedList::insertAtEnd(int value) {
    cout << "not allowed in stack! Use insertAtStart instead.\n";
}

void LinkedList::insertAtPosition(int value, int position) {
    cout << "not allowed in stack! Use insertAtStart instead.\n";
}

void LinkedList::deleteFromEnd() {
    cout << "not allowed in stack! Use deleteAtStart instead.\n";
}

void LinkedList::deleteAtPosition(int position) {
    cout << "not allowed in stack! Use deleteAtStart instead.\n";
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
        cout << "Stack is empty!\n";
        return;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;   // store next node
        current->next = prev;   // reverse link
        prev = current;         // move prev forward
        current = next;         // move current forward
    }

    head = prev;   // new top of stack

    cout << "Stack reversed successfully.\n";
}

void LinkedList::display() {
    if (head == NULL) {
        cout << "Stack is empty!\n";
        return;
    }

    Node* temp = head;
    cout << "Stack (Top to Bottom): ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void LinkedList::concatenate(LinkedList& otherList) {
    if (head == NULL) {
        head = otherList.head;
        cout << "Stack concatenated successfully.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = otherList.head;
    cout << "Stack concatenated successfully.\n";
}

void LinkedList::split(int position, LinkedList& secondList)
{
    if (head == NULL) {
        cout << "Stack is empty!\n";
        return;
    }

    if (position <= 0) {
        cout << "Invalid position!\n";
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse to the split position
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position exceeds stack size!\n";
        return;
    }

    // Second stack starts from next node
    secondList.head = temp->next;

    // Break the stack
    temp->next = NULL;

    cout << "Stack split successfully.\n";
}

int LinkedList::findLargest() {
    if (head == NULL) {
        cout << "Stack is empty!\n";
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
        cout << "Stack is empty!\n";
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
