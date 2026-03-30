#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// ─── Node for queue
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// ─── Doubly node for deque/circular deque
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

// ─── Char doubly node for palindrome deque
class CharDNode {
public:
    char data;
    CharDNode* prev;
    CharDNode* next;

    CharDNode(char value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

//  General queue
struct Queue {
    Node* front;
    Node* rear;

    Queue();
    void enqueue(int value);
    int  dequeue();
    int  peekFront();
    int  peekRear();
    bool isEmpty();
    int  countNodes();
    void display();
};

//  General deque (non-circular)
struct Deque {
    DNode* front;
    DNode* rear;

    Deque();
    void insertFront(int value);
    void insertRear(int value);
    int  deleteFront();
    int  deleteRear();
    bool isEmpty();
    int  countNodes();
    void display();
    void clear();
};

//  Q3 – Circular deque using linked list
struct CircularDeque {
    DNode* front;

    CircularDeque();
    void insertFront(int value);
    void insertRear(int value);
    int  deleteFront();
    int  deleteRear();
    bool isEmpty();
    void display();
};

//  Q5 – Char deque for palindrome
struct CharDeque {
    CharDNode* front;
    CharDNode* rear;

    CharDeque();
    void insertRear(char value);
    char deleteFront();
    char deleteRear();
    bool isEmpty();
};

//  Q6 – Call center using multiple queues
struct CallCenter {
    Queue urgent;
    Queue normal;
    Queue low;

    void addCall(int inquiryId, int priorityLevel);
    void processCall();
    void displayAll();
};

//  Stack for Q7 (deque using two stacks)
struct IntStack {
    Node* top;

    IntStack();
    void push(int value);
    int  pop();
    int  peek();
    bool isEmpty();
};

//  Q7 – Deque using two stacks
struct TwoStackDeque {
    IntStack left;
    IntStack right;

    void insertFront(int value);
    void insertRear(int value);
    int  deleteFront();
    int  deleteRear();
    bool isEmpty();
    void display();
};

//  Q9 – Queue using priority queue behavior
class PNode {
public:
    int data;
    int priority;
    PNode* next;

    PNode(int value, int pr) {
        data = value;
        priority = pr;
        next = NULL;
    }
};

struct PriorityQueueLL {
    PNode* front;

    PriorityQueueLL();
    void enqueue(int value, int priority);
    int  dequeue();
    bool isEmpty();
    void display();
};

//  Q1 – Reverse queue using only queue operations
void reverseQueueUsingOps(Queue& q);

//  Q2 – Sort deque in descending order
void sortDequeDescending(Deque& dq);

//  Q4 – Check if two queues are identical
bool areQueuesIdentical(Queue& q1, Queue& q2);

//  Q5 – Valid palindrome ignoring non-alphanumeric chars
bool isValidPalindromeUsingDeque(const string& text);

//  Q8 – kth largest in queue without modifying queue
int kthLargestInQueue(Queue& q, int k);

//  Q10 – Split two deques into three equal deques
void splitTwoDequesIntoThreeEqual(Deque& d1, Deque& d2, Deque& a, Deque& b, Deque& c);

//  Q11 – Split two queues into three queues (size of one = sum of other two)
void splitTwoQueuesWithSumRule(Queue& q1, Queue& q2, Queue& a, Queue& b, Queue& c);

//  Q12 – Sort two deques then concatenate from rear side
void sortAndConcatFromRear(Deque& d1, Deque& d2, Deque& result);

//  Q13 – Print rear, front and middle of queue
void printFrontRearMiddle(Queue& q);

//  Q14 – Print values at indices 1, 3, 6, 10, ... from front
void printTriangularIndexValues(Queue& q);

//  Q15 – Remove center while size > 3, then print remaining three
void shrinkDequeToThreeByRemovingCenter(Deque& dq);

#endif
