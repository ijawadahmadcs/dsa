#include "queue.h"

//  General Queue
Queue::Queue() {
    front = NULL;
    rear = NULL;
}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow!\n";
        return -1;
    }

    Node* temp = front;
    int val = temp->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    delete temp;
    return val;
}

int Queue::peekFront() {
    if (front == NULL) {
        cout << "Queue is empty!\n";
        return -1;
    }
    return front->data;
}

int Queue::peekRear() {
    if (rear == NULL) {
        cout << "Queue is empty!\n";
        return -1;
    }
    return rear->data;
}

bool Queue::isEmpty() {
    return front == NULL;
}

int Queue::countNodes() {
    int count = 0;
    Node* cur = front;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

void Queue::display() {
    if (front == NULL) {
        cout << "Queue is empty!\n";
        return;
    }

    cout << "Queue (front -> rear): ";
    Node* cur = front;
    while (cur != NULL) {
        cout << cur->data << " -> ";
        cur = cur->next;
    }
    cout << "NULL\n";
}

//  General Deque
Deque::Deque() {
    front = NULL;
    rear = NULL;
}

void Deque::insertFront(int value) {
    DNode* newNode = new DNode(value);
    if (front == NULL) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

void Deque::insertRear(int value) {
    DNode* newNode = new DNode(value);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

int Deque::deleteFront() {
    if (front == NULL) {
        cout << "Deque Underflow!\n";
        return -1;
    }

    DNode* temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }

    delete temp;
    return val;
}

int Deque::deleteRear() {
    if (rear == NULL) {
        cout << "Deque Underflow!\n";
        return -1;
    }

    DNode* temp = rear;
    int val = temp->data;
    rear = rear->prev;

    if (rear == NULL) {
        front = NULL;
    } else {
        rear->next = NULL;
    }

    delete temp;
    return val;
}

bool Deque::isEmpty() {
    return front == NULL;
}

int Deque::countNodes() {
    int count = 0;
    DNode* cur = front;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

void Deque::display() {
    if (front == NULL) {
        cout << "Deque is empty!\n";
        return;
    }

    cout << "Deque (front -> rear): ";
    DNode* cur = front;
    while (cur != NULL) {
        cout << cur->data << " -> ";
        cur = cur->next;
    }
    cout << "NULL\n";
}

void Deque::clear() {
    while (!isEmpty()) {
        deleteFront();
    }
}

//  Q3 – Circular Deque
CircularDeque::CircularDeque() {
    front = NULL;
}

void CircularDeque::insertFront(int value) {
    DNode* newNode = new DNode(value);

    if (front == NULL) {
        front = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    DNode* rear = front->prev;
    newNode->next = front;
    newNode->prev = rear;
    rear->next = newNode;
    front->prev = newNode;
    front = newNode;
}

void CircularDeque::insertRear(int value) {
    DNode* newNode = new DNode(value);

    if (front == NULL) {
        front = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    DNode* rear = front->prev;
    newNode->next = front;
    newNode->prev = rear;
    rear->next = newNode;
    front->prev = newNode;
}

int CircularDeque::deleteFront() {
    if (front == NULL) {
        cout << "Circular Deque Underflow!\n";
        return -1;
    }

    int val = front->data;

    if (front->next == front) {
        delete front;
        front = NULL;
        return val;
    }

    DNode* rear = front->prev;
    DNode* temp = front;
    front = front->next;
    front->prev = rear;
    rear->next = front;
    delete temp;

    return val;
}

int CircularDeque::deleteRear() {
    if (front == NULL) {
        cout << "Circular Deque Underflow!\n";
        return -1;
    }

    DNode* rear = front->prev;
    int val = rear->data;

    if (rear == front) {
        delete rear;
        front = NULL;
        return val;
    }

    DNode* newRear = rear->prev;
    newRear->next = front;
    front->prev = newRear;
    delete rear;

    return val;
}

bool CircularDeque::isEmpty() {
    return front == NULL;
}

void CircularDeque::display() {
    if (front == NULL) {
        cout << "Circular Deque is empty!\n";
        return;
    }

    cout << "Circular Deque (front -> rear): ";
    DNode* cur = front;
    do {
        cout << cur->data << " -> ";
        cur = cur->next;
    } while (cur != front);
    cout << "(back to front)\n";
}

//  Q5 – Char Deque
CharDeque::CharDeque() {
    front = NULL;
    rear = NULL;
}

void CharDeque::insertRear(char value) {
    CharDNode* newNode = new CharDNode(value);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

char CharDeque::deleteFront() {
    if (front == NULL) return '\0';

    CharDNode* temp = front;
    char val = temp->data;
    front = front->next;

    if (front == NULL) rear = NULL;
    else front->prev = NULL;

    delete temp;
    return val;
}

char CharDeque::deleteRear() {
    if (rear == NULL) return '\0';

    CharDNode* temp = rear;
    char val = temp->data;
    rear = rear->prev;

    if (rear == NULL) front = NULL;
    else rear->next = NULL;

    delete temp;
    return val;
}

bool CharDeque::isEmpty() {
    return front == NULL;
}

//  Q6 – Call Center
void CallCenter::addCall(int inquiryId, int priorityLevel) {
    if (priorityLevel == 3) {
        urgent.enqueue(inquiryId);
        cout << "Added inquiry " << inquiryId << " to URGENT queue.\n";
    } else if (priorityLevel == 2) {
        normal.enqueue(inquiryId);
        cout << "Added inquiry " << inquiryId << " to NORMAL queue.\n";
    } else {
        low.enqueue(inquiryId);
        cout << "Added inquiry " << inquiryId << " to LOW queue.\n";
    }
}

void CallCenter::processCall() {
    if (!urgent.isEmpty()) {
        cout << "Processing URGENT inquiry: " << urgent.dequeue() << "\n";
    } else if (!normal.isEmpty()) {
        cout << "Processing NORMAL inquiry: " << normal.dequeue() << "\n";
    } else if (!low.isEmpty()) {
        cout << "Processing LOW inquiry: " << low.dequeue() << "\n";
    } else {
        cout << "No pending inquiries.\n";
    }
}

void CallCenter::displayAll() {
    cout << "Urgent Queue: ";
    urgent.display();
    cout << "Normal Queue: ";
    normal.display();
    cout << "Low Queue: ";
    low.display();
}

//  Stack for Q7
IntStack::IntStack() {
    top = NULL;
}

void IntStack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

int IntStack::pop() {
    if (top == NULL) return -1;

    Node* temp = top;
    int val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

int IntStack::peek() {
    if (top == NULL) return -1;
    return top->data;
}

bool IntStack::isEmpty() {
    return top == NULL;
}

//  Q7 – Deque using two stacks
void TwoStackDeque::insertFront(int value) {
    left.push(value);
    cout << "Inserted " << value << " at front.\n";
}

void TwoStackDeque::insertRear(int value) {
    right.push(value);
    cout << "Inserted " << value << " at rear.\n";
}

int TwoStackDeque::deleteFront() {
    if (left.isEmpty()) {
        while (!right.isEmpty()) left.push(right.pop());
    }

    if (left.isEmpty()) {
        cout << "Deque Underflow!\n";
        return -1;
    }

    int val = left.pop();
    cout << "Deleted from front: " << val << "\n";
    return val;
}

int TwoStackDeque::deleteRear() {
    if (right.isEmpty()) {
        while (!left.isEmpty()) right.push(left.pop());
    }

    if (right.isEmpty()) {
        cout << "Deque Underflow!\n";
        return -1;
    }

    int val = right.pop();
    cout << "Deleted from rear: " << val << "\n";
    return val;
}

bool TwoStackDeque::isEmpty() {
    return left.isEmpty() && right.isEmpty();
}

void TwoStackDeque::display() {
    if (isEmpty()) {
        cout << "Deque is empty!\n";
        return;
    }

    cout << "Deque (front -> rear): ";

    Node* cur = left.top;
    while (cur != NULL) {
        cout << cur->data << " -> ";
        cur = cur->next;
    }

    int rCount = 0;
    cur = right.top;
    while (cur != NULL) {
        rCount++;
        cur = cur->next;
    }

    if (rCount > 0) {
        int* arr = new int[rCount];
        cur = right.top;
        int i = 0;
        while (cur != NULL) {
            arr[i++] = cur->data;
            cur = cur->next;
        }

        for (int j = rCount - 1; j >= 0; j--) {
            cout << arr[j] << " -> ";
        }

        delete[] arr;
    }

    cout << "NULL\n";
}

//  Q9 – Priority Queue (linked list)
PriorityQueueLL::PriorityQueueLL() {
    front = NULL;
}

void PriorityQueueLL::enqueue(int value, int priority) {
    PNode* newNode = new PNode(value, priority);

    if (front == NULL || priority > front->priority) {
        newNode->next = front;
        front = newNode;
        cout << "Inserted " << value << " with priority " << priority << ".\n";
        return;
    }

    PNode* cur = front;
    while (cur->next != NULL && cur->next->priority >= priority) {
        cur = cur->next;
    }

    newNode->next = cur->next;
    cur->next = newNode;
    cout << "Inserted " << value << " with priority " << priority << ".\n";
}

int PriorityQueueLL::dequeue() {
    if (front == NULL) {
        cout << "Priority Queue Underflow!\n";
        return -1;
    }

    PNode* temp = front;
    int val = temp->data;
    front = front->next;
    delete temp;
    return val;
}

bool PriorityQueueLL::isEmpty() {
    return front == NULL;
}

void PriorityQueueLL::display() {
    if (front == NULL) {
        cout << "Priority queue is empty!\n";
        return;
    }

    cout << "Priority Queue (high -> low): ";
    PNode* cur = front;
    while (cur != NULL) {
        cout << "[" << cur->data << ",p=" << cur->priority << "] -> ";
        cur = cur->next;
    }
    cout << "NULL\n";
}

//  Q1 – Reverse queue using only queue operations
void reverseQueueUsingOps(Queue& q) {
    if (q.isEmpty()) return;

    int val = q.dequeue();
    reverseQueueUsingOps(q);
    q.enqueue(val);
}

//  Q2 – Sort deque in descending order (bubble sort by data swap)
void sortDequeDescending(Deque& dq) {
    if (dq.isEmpty() || dq.front == dq.rear) {
        cout << "Deque already sorted (0/1 element).\n";
        return;
    }

    bool swapped;
    do {
        swapped = false;
        DNode* cur = dq.front;
        while (cur != NULL && cur->next != NULL) {
            if (cur->data < cur->next->data) {
                int temp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = temp;
                swapped = true;
            }
            cur = cur->next;
        }
    } while (swapped);

    cout << "Deque sorted in descending order.\n";
}

//  Q4 – Check if two queues are identical
bool areQueuesIdentical(Queue& q1, Queue& q2) {
    Node* c1 = q1.front;
    Node* c2 = q2.front;

    while (c1 != NULL && c2 != NULL) {
        if (c1->data != c2->data) return false;
        c1 = c1->next;
        c2 = c2->next;
    }

    return c1 == NULL && c2 == NULL;
}

//  Q5 – Valid palindrome ignoring non-alphanumeric chars
bool isValidPalindromeUsingDeque(const string& text) {
    CharDeque dq;

    for (int i = 0; i < (int)text.length(); i++) {
        char c = text[i];
        if (isalnum((unsigned char)c)) {
            dq.insertRear((char)tolower((unsigned char)c));
        }
    }

    while (!dq.isEmpty()) {
        char left = dq.deleteFront();
        if (dq.isEmpty()) return true;
        char right = dq.deleteRear();
        if (left != right) return false;
    }

    return true;
}

//  Q8 – kth largest in queue without modifying queue
int kthLargestInQueue(Queue& q, int k) {
    int n = q.countNodes();

    if (k <= 0 || k > n) {
        cout << "Invalid k value!\n";
        return -1;
    }

    int* arr = new int[n];
    Node* cur = q.front;
    int i = 0;
    while (cur != NULL) {
        arr[i++] = cur->data;
        cur = cur->next;
    }

    for (int p = 0; p < n - 1; p++) {
        for (int j = 0; j < n - p - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int ans = arr[k - 1];
    delete[] arr;
    return ans;
}

//  Q10 – Split two deques into three equal deques
void splitTwoDequesIntoThreeEqual(Deque& d1, Deque& d2, Deque& a, Deque& b, Deque& c) {
    int total = d1.countNodes() + d2.countNodes();

    if (total % 3 != 0) {
        cout << "Cannot split into three equal deques (total not divisible by 3).\n";
        return;
    }

    int each = total / 3;

    a.clear();
    b.clear();
    c.clear();

    int index = 0;
    DNode* cur = d1.front;
    while (cur != NULL) {
        if (index < each) a.insertRear(cur->data);
        else if (index < 2 * each) b.insertRear(cur->data);
        else c.insertRear(cur->data);
        index++;
        cur = cur->next;
    }

    cur = d2.front;
    while (cur != NULL) {
        if (index < each) a.insertRear(cur->data);
        else if (index < 2 * each) b.insertRear(cur->data);
        else c.insertRear(cur->data);
        index++;
        cur = cur->next;
    }

    cout << "Split done: each deque has " << each << " elements.\n";
}

//  Q11 – Split two queues into 3 queues with size rule
void splitTwoQueuesWithSumRule(Queue& q1, Queue& q2, Queue& a, Queue& b, Queue& c) {
    int total = q1.countNodes() + q2.countNodes();

    if (total % 2 != 0) {
        cout << "Cannot satisfy size rule because total elements are odd.\n";
        return;
    }

    int sumAB = total / 2;
    int aSize = sumAB / 2;
    int bSize = sumAB - aSize;
    int cSize = sumAB;

    while (!a.isEmpty()) a.dequeue();
    while (!b.isEmpty()) b.dequeue();
    while (!c.isEmpty()) c.dequeue();

    int index = 0;
    Node* cur = q1.front;
    while (cur != NULL) {
        if (index < aSize) a.enqueue(cur->data);
        else if (index < aSize + bSize) b.enqueue(cur->data);
        else if (index < aSize + bSize + cSize) c.enqueue(cur->data);
        index++;
        cur = cur->next;
    }

    cur = q2.front;
    while (cur != NULL) {
        if (index < aSize) a.enqueue(cur->data);
        else if (index < aSize + bSize) b.enqueue(cur->data);
        else if (index < aSize + bSize + cSize) c.enqueue(cur->data);
        index++;
        cur = cur->next;
    }

    cout << "Split done with rule: size(C) = size(A) + size(B).\n";
    cout << "Sizes => A=" << a.countNodes() << ", B=" << b.countNodes() << ", C=" << c.countNodes() << "\n";
}

//  Q12 – Sort two deques then concatenate from rear side
void sortAndConcatFromRear(Deque& d1, Deque& d2, Deque& result) {
    sortDequeDescending(d1);
    sortDequeDescending(d2);

    result.clear();

    DNode* cur = d1.rear;
    while (cur != NULL) {
        result.insertRear(cur->data);
        cur = cur->prev;
    }

    cur = d2.rear;
    while (cur != NULL) {
        result.insertRear(cur->data);
        cur = cur->prev;
    }

    cout << "Sorted both deques and concatenated from rear side.\n";
}

//  Q13 – Print rear, front and middle
void printFrontRearMiddle(Queue& q) {
    if (q.isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }

    int n = q.countNodes();
    int midIndex = n / 2;

    Node* cur = q.front;
    int idx = 0;
    int midValue = q.front->data;

    while (cur != NULL) {
        if (idx == midIndex) {
            midValue = cur->data;
            break;
        }
        idx++;
        cur = cur->next;
    }

    cout << "Front value : " << q.peekFront() << "\n";
    cout << "Rear value  : " << q.peekRear() << "\n";
    cout << "Middle value: " << midValue << "\n";
}

//  Q14 – Print triangular index values (1,3,6,10,...)
void printTriangularIndexValues(Queue& q) {
    if (q.isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }

    int n = q.countNodes();
    int tri = 1;
    int add = 2;

    cout << "Values at indices 1, 3, 6, 10, ... from front: ";
    while (tri <= n) {
        Node* cur = q.front;
        int idx = 1;
        while (idx < tri && cur != NULL) {
            cur = cur->next;
            idx++;
        }

        if (cur != NULL) cout << cur->data << " ";

        tri += add;
        add++;
    }

    cout << "\n";
}

//  Q15 – Remove center until size becomes 3
void shrinkDequeToThreeByRemovingCenter(Deque& dq) {
    int n = dq.countNodes();

    while (n > 3) {
        int midIndex = n / 2;

        DNode* cur = dq.front;
        int idx = 0;
        while (idx < midIndex && cur != NULL) {
            cur = cur->next;
            idx++;
        }

        if (cur == dq.front) {
            dq.deleteFront();
        } else if (cur == dq.rear) {
            dq.deleteRear();
        } else if (cur != NULL) {
            DNode* p = cur->prev;
            DNode* nNode = cur->next;
            p->next = nNode;
            nNode->prev = p;
            cout << "Removed center value: " << cur->data << "\n";
            delete cur;
        }

        n = dq.countNodes();
    }

    if (dq.countNodes() == 3) {
        cout << "Final three values: ";
        dq.display();
    } else {
        cout << "Deque has less than 3 values after processing.\n";
    }
}
