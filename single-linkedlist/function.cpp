#include "linkedlist.h"

static void swapNodeData(Node* first, Node* second) {
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

static Node* getMiddleNode(Node* head) {
    if (head == NULL)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

static Node* mergeSortedLists(Node* left, Node* right) {
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = mergeSortedLists(left->next, right);
    } else {
        result = right;
        result->next = mergeSortedLists(left, right->next);
    }

    return result;
}

static void mergeSortNodes(Node** headRef) {
    Node* head = *headRef;
    if (head == NULL || head->next == NULL)
        return;

    Node* middle = getMiddleNode(head);
    Node* nextToMiddle = middle->next;

    middle->next = NULL;

    mergeSortNodes(&head);
    mergeSortNodes(&nextToMiddle);

    *headRef = mergeSortedLists(head, nextToMiddle);
}

static Node* partitionLast(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL;
    Node* current = head;
    Node* tail = pivot;

    while (current != pivot) {
        if (current->data < pivot->data) {
            if (*newHead == NULL)
                *newHead = current;
            prev = current;
            current = current->next;
        } else {
            if (prev != NULL)
                prev->next = current->next;
            Node* temp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if (*newHead == NULL)
        *newHead = pivot;

    *newEnd = tail;
    return pivot;
}

static Node* quickSortRecur(Node* head, Node* end) {
    if (head == NULL || head == end)
        return head;

    Node* newHead = NULL;
    Node* newEnd = NULL;

    Node* pivot = partitionLast(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;

        newHead = quickSortRecur(newHead, temp);

        temp = newHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

static Node* getTailNode(Node* current) {
    while (current != NULL && current->next != NULL)
        current = current->next;
    return current;
}

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


void LinkedList::bubbleSort() {
    if (head == NULL || head->next == NULL)
        return;

    bool swapped;
    Node* end = NULL;

    do {
        swapped = false;
        Node* current = head;

        while (current->next != end) {
            if (current->data > current->next->data) {
                swapNodeData(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
        end = current;
    } while (swapped);
}


void LinkedList::selectionSort() {
    if (head == NULL || head->next == NULL)
        return;

    for (Node* start = head; start != NULL; start = start->next) {
        Node* minNode = start;
        for (Node* current = start->next; current != NULL; current = current->next) {
            if (current->data < minNode->data)
                minNode = current;
        }
        if (minNode != start)
            swapNodeData(start, minNode);
    }
}


void LinkedList::mergeSort() {
    mergeSortNodes(&head);
}


void LinkedList::quickSort() {
    head = quickSortRecur(head, getTailNode(head));
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