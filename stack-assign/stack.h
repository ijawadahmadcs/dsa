#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
using namespace std;

// ─── Node for general stack 
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// ─── Node that stores a pointer (Q13) 
class PtrNode {
public:
    int* ptr;
    PtrNode* next;

    PtrNode(int* p) {
        ptr = p;
        next = NULL;
    }
};

// ─── Char Node (Q6, Q8) 
class CharNode {
public:
    char data;
    CharNode* next;

    CharNode(char value) {
        data = value;
        next = NULL;
    }
};

//  Q1 – Two stacks in one linked list (stack1 from front, stack2 from rear)
struct TwoStack {
    Node* top1;   // stack 1 grows forward
    Node* top2;   // stack 2 grows forward (logical rear)

    TwoStack();
    void push1(int value);
    void push2(int value);
    int  pop1();
    int  pop2();
    void display();
};

//  Q2 – Even integers in stack1, odd integers in stack2
struct EvenOddStack {
    Node* evenTop;
    Node* oddTop;

    EvenOddStack();
    void push(int value);
    int  popEven();
    int  popOdd();
    void display();
};

//  Q3 – Next greater element
struct Stack {
    Node* top;

    Stack();
    void push(int value);
    int  pop();
    int  peek();
    bool isEmpty();
    void display();
    int  countNodes();
};

void findNextGreater(Stack& s);

//  Q4 – Constant-size stack (replace smallest on overflow)
struct ConstStack {
    Node* top;
    int   capacity;
    int   size;

    ConstStack(int cap);
    void push(int value);
    int  pop();
    int  peek();
    bool isEmpty();
    int  findSmallest();
    void removeSmallest();
    void display();
};

//  Q5 – Sort a linked list using two stacks
void sortUsingTwoStacks(Stack& s);

//  Q6 – Palindrome check using char stack
struct CharStack {
    CharNode* top;

    CharStack();
    void push(char value);
    char pop();
    char peek();
    bool isEmpty();
};

bool isPalindrome(const string& str);

//  Q7 – Copy a stack
Stack* copyStack(Stack* src);

//  Q8 – Balanced brackets check
bool isBalanced(const string& expr);

//  Q9 – Remove duplicates from stack
void removeDuplicates(Stack& s);

//  Q10 – Intersection of two stacks
Stack* intersection(Stack& s1, Stack& s2);

//  Q11 – Subset check
bool isSubset(Stack& s1, Stack& s2);

//  Q12 – Swap top two elements
void swapTop(Stack& s);

//  Q13 – Stack of pointers
struct PtrStack {
    PtrNode* top;

    PtrStack();
    void push(int* ptr);
    int* pop();
    bool isEmpty();
    void display();
};

#endif
