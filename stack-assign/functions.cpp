#include "stack.h"

//  Q1 – Two stacks in one linked list
TwoStack::TwoStack() {
    top1 = NULL;
    top2 = NULL;
}

void TwoStack::push1(int value) {
    Node* newNode = new Node(value);
    newNode->next = top1;
    top1 = newNode;
    cout << "Pushed " << value << " onto Stack 1.\n";
}

void TwoStack::push2(int value) {
    Node* newNode = new Node(value);
    newNode->next = top2;
    top2 = newNode;
    cout << "Pushed " << value << " onto Stack 2.\n";
}

int TwoStack::pop1() {
    if (top1 == NULL) {
        cout << "Stack 1 Underflow!\n";
        return -1;
    }
    Node* temp = top1;
    int val = temp->data;
    top1 = top1->next;
    delete temp;
    cout << "Popped " << val << " from Stack 1.\n";
    return val;
}

int TwoStack::pop2() {
    if (top2 == NULL) {
        cout << "Stack 2 Underflow!\n";
        return -1;
    }
    Node* temp = top2;
    int val = temp->data;
    top2 = top2->next;
    delete temp;
    cout << "Popped " << val << " from Stack 2.\n";
    return val;
}

void TwoStack::display() {
    cout << "Stack 1 (top -> bottom): ";
    Node* temp = top1;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    cout << "Stack 2 (top -> bottom): ";
    temp = top2;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

//  Q2 – Even/Odd stacks
EvenOddStack::EvenOddStack() {
    evenTop = NULL;
    oddTop  = NULL;
}

void EvenOddStack::push(int value) {
    Node* newNode = new Node(value);
    if (value % 2 == 0) {
        newNode->next = evenTop;
        evenTop = newNode;
        cout << "Pushed " << value << " onto Even Stack.\n";
    } else {
        newNode->next = oddTop;
        oddTop = newNode;
        cout << "Pushed " << value << " onto Odd Stack.\n";
    }
}

int EvenOddStack::popEven() {
    if (evenTop == NULL) {
        cout << "Even Stack Underflow!\n";
        return -1;
    }
    Node* temp = evenTop;
    int val = temp->data;
    evenTop = evenTop->next;
    delete temp;
    cout << "Popped " << val << " from Even Stack.\n";
    return val;
}

int EvenOddStack::popOdd() {
    if (oddTop == NULL) {
        cout << "Odd Stack Underflow!\n";
        return -1;
    }
    Node* temp = oddTop;
    int val = temp->data;
    oddTop = oddTop->next;
    delete temp;
    cout << "Popped " << val << " from Odd Stack.\n";
    return val;
}

void EvenOddStack::display() {
    cout << "Even Stack (top -> bottom): ";
    Node* temp = evenTop;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    cout << "Odd Stack  (top -> bottom): ";
    temp = oddTop;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

//  Q3 – General Stack (reused by Q4, Q5, Q7, Q9, Q10, Q11, Q12)
Stack::Stack() {
    top = NULL;
}

void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

int Stack::pop() {
    if (top == NULL) {
        cout << "Stack Underflow!\n";
        return -1;
    }
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

int Stack::peek() {
    if (top == NULL) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == NULL;
}

void Stack::display() {
    if (top == NULL) {
        cout << "Stack is empty!\n";
        return;
    }
    Node* temp = top;
    cout << "Stack (top -> bottom): ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int Stack::countNodes() {
    int count = 0;
    Node* temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// ─── Q3: Next Greater Element 
void findNextGreater(Stack& s) {
    if (s.isEmpty()) {
        cout << "Stack is empty!\n";
        return;
    }

    // copy elements into an array (top-to-bottom order)
    int count = s.countNodes();
    int* arr = new int[count];
    Stack temp;

    // unload into array and a temp stack
    int i = count - 1;
    Node* cur = s.top;
    while (cur != NULL) {
        arr[i--] = cur->data;
        cur = cur->next;
    }

    cout << "Element -> Next Greater\n";
    Stack helper;

    for (int j = count - 1; j >= 0; j--) {
        while (!helper.isEmpty() && helper.peek() <= arr[j]) {
            helper.pop();
        }
        if (helper.isEmpty()) {
            cout << arr[j] << " -> -1\n";
        } else {
            cout << arr[j] << " -> " << helper.peek() << "\n";
        }
        helper.push(arr[j]);
    }

    delete[] arr;
}

//  Q4 – Constant-size stack
ConstStack::ConstStack(int cap) {
    top      = NULL;
    capacity = cap;
    size     = 0;
}

int ConstStack::findSmallest() {
    if (top == NULL) return -1;
    int smallest = top->data;
    Node* temp = top->next;
    while (temp != NULL) {
        if (temp->data < smallest)
            smallest = temp->data;
        temp = temp->next;
    }
    return smallest;
}

void ConstStack::removeSmallest() {
    if (top == NULL) return;

    int smallest = findSmallest();
    Node* temp = top;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == smallest) {
            if (prev == NULL) {
                top = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            size--;
            cout << "Replaced smallest (" << smallest << ") to make room.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void ConstStack::push(int value) {
    if (size == capacity) {
        int smallest = findSmallest();
        if (value <= smallest) {
            cout << "Value " << value << " is not greater than smallest (" << smallest << "). Not inserted.\n";
            return;
        }
        removeSmallest();
    }
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    size++;
    cout << "Pushed " << value << ".\n";
}

int ConstStack::pop() {
    if (top == NULL) {
        cout << "Stack Underflow!\n";
        return -1;
    }
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    delete temp;
    size--;
    cout << "Popped " << val << ".\n";
    return val;
}

int ConstStack::peek() {
    if (top == NULL) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return top->data;
}

bool ConstStack::isEmpty() {
    return top == NULL;
}

void ConstStack::display() {
    if (top == NULL) {
        cout << "Stack is empty!\n";
        return;
    }
    Node* temp = top;
    cout << "Stack (top -> bottom): ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// ═══════════════════════════════════════════════════════════════════════════════
//  Q5 – Sort a stack using two auxiliary stacks
// ═══════════════════════════════════════════════════════════════════════════════

void sortUsingTwoStacks(Stack& s) {
    if (s.isEmpty()) {
        cout << "Stack is empty!\n";
        return;
    }

    Stack sorted;   // will hold elements in sorted order (smallest on top)
    Stack temp;

    // move all to sorted using insertion sort logic
    while (!s.isEmpty()) {
        int cur = s.pop();

        // move elements from sorted to temp until we find the right spot
        while (!sorted.isEmpty() && sorted.peek() > cur) {
            temp.push(sorted.pop());
        }

        sorted.push(cur);

        // move back
        while (!temp.isEmpty()) {
            sorted.push(temp.pop());
        }
    }

    // move sorted back to original stack (so largest is on top)
    while (!sorted.isEmpty()) {
        s.push(sorted.pop());
    }

    cout << "Stack sorted successfully.\n";
}

// ═══════════════════════════════════════════════════════════════════════════════
//  Q6 – Palindrome check
// ═══════════════════════════════════════════════════════════════════════════════

CharStack::CharStack() {
    top = NULL;
}

void CharStack::push(char value) {
    CharNode* newNode = new CharNode(value);
    newNode->next = top;
    top = newNode;
}

char CharStack::pop() {
    if (top == NULL) return '\0';
    CharNode* temp = top;
    char val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

char CharStack::peek() {
    if (top == NULL) return '\0';
    return top->data;
}

bool CharStack::isEmpty() {
    return top == NULL;
}

bool isPalindrome(const string& str) {
    CharStack s;
    int len = str.length();

    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != s.pop()) {
            return false;
        }
    }

    return true;
}

// ═══════════════════════════════════════════════════════════════════════════════
//  Q7 – Copy a stack
// ═══════════════════════════════════════════════════════════════════════════════

Stack* copyStack(Stack* src) {
    if (src == NULL) return NULL;

    Stack* copy    = new Stack();
    Stack  tempStk;

    // unload src into temp (reverses order)
    Node* cur = src->top;
    while (cur != NULL) {
        tempStk.push(cur->data);
        cur = cur->next;
    }

    // unload temp into copy (restores original order)
    while (!tempStk.isEmpty()) {
        copy->push(tempStk.pop());
    }

    cout << "Stack copied successfully.\n";
    return copy;
}

// ═══════════════════════════════════════════════════════════════════════════════
//  Q8 – Balanced brackets
// ═══════════════════════════════════════════════════════════════════════════════

bool isBalanced(const string& expr) {
    CharStack s;

    for (int i = 0; i < (int)expr.length(); i++) {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty()) return false;

            char top = s.pop();

            if (c == ')' && top != '(') return false;
            if (c == '}' && top != '{') return false;
            if (c == ']' && top != '[') return false;
        }
    }

    return s.isEmpty();
}

// ═══════════════════════════════════════════════════════════════════════════════
//  Q9 – Remove duplicates from stack
// ═══════════════════════════════════════════════════════════════════════════════

void removeDuplicates(Stack& s) {
    if (s.isEmpty()) {
        cout << "Stack is empty!\n";
        return;
    }

    Stack temp;
    Stack result;

    // unload s into temp (bottom-to-top becomes temp's top-to-bottom)
    while (!s.isEmpty()) {
        temp.push(s.pop());
    }

    // push from temp into result, skip if already seen
    while (!temp.isEmpty()) {
        int val = temp.pop();
        bool found = false;

        Node* cur = result.top;
        while (cur != NULL) {
            if (cur->data == val) {
                found = true;
                break;
            }
            cur = cur->next;
        }

        if (!found) {
            result.push(val);
        }
    }

    // move result back to s (re-reverse so original order is preserved)
    Stack restore;
    while (!result.isEmpty()) {
        restore.push(result.pop());
    }
    while (!restore.isEmpty()) {
        s.push(restore.pop());
    }

    cout << "Duplicates removed.\n";
}

// ═══════════════════════════════════════════════════════════════════════════════
//  Q10 – Intersection of two stacks
// ═══════════════════════════════════════════════════════════════════════════════

Stack* intersection(Stack& s1, Stack& s2) {
    Stack* result = new Stack();
    Stack  temp;

    // copy s1 elements to temp (preserves order)
    Node* cur = s1.top;
    while (cur != NULL) {
        temp.push(cur->data);
        cur = cur->next;
    }

    while (!temp.isEmpty()) {
        int val = temp.pop();

        // check if val exists in s2
        Node* cur2 = s2.top;
        bool found = false;
        while (cur2 != NULL) {
            if (cur2->data == val) {
                found = true;
                break;
            }
            cur2 = cur2->next;
        }

        if (found) {
            // check not already in result
            Node* rc = result->top;
            bool dup = false;
            while (rc != NULL) {
                if (rc->data == val) { dup = true; break; }
                rc = rc->next;
            }
            if (!dup) result->push(val);
        }
    }

    cout << "Intersection computed.\n";
    return result;
}

// ═══════════════════════════════════════════════════════════════════════════════
//  Q11 – Subset check
// ═══════════════════════════════════════════════════════════════════════════════

bool isSubset(Stack& s1, Stack& s2) {
    Node* cur = s1.top;

    while (cur != NULL) {
        int val = cur->data;
        bool found = false;

        Node* cur2 = s2.top;
        while (cur2 != NULL) {
            if (cur2->data == val) {
                found = true;
                break;
            }
            cur2 = cur2->next;
        }

        if (!found) return false;
        cur = cur->next;
    }

    return true;
}

// ═══════════════════════════════════════════════════════════════════════════════
//  Q12 – Swap top two elements
// ═══════════════════════════════════════════════════════════════════════════════

void swapTop(Stack& s) {
    if (s.countNodes() < 2) {
        cout << "Need at least 2 elements to swap!\n";
        return;
    }

    int first  = s.pop();
    int second = s.pop();

    s.push(first);
    s.push(second);

    cout << "Top two elements swapped.\n";
}

// ═══════════════════════════════════════════════════════════════════════════════
//  Q13 – Stack of pointers
// ═══════════════════════════════════════════════════════════════════════════════

PtrStack::PtrStack() {
    top = NULL;
}

void PtrStack::push(int* ptr) {
    PtrNode* newNode = new PtrNode(ptr);
    newNode->next = top;
    top = newNode;
    cout << "Pushed pointer (value = " << *ptr << ") onto stack.\n";
}

int* PtrStack::pop() {
    if (top == NULL) {
        cout << "Stack Underflow!\n";
        return NULL;
    }
    PtrNode* temp = top;
    int* ptr = temp->ptr;
    top = top->next;
    delete temp;   // free the node, NOT the pointer yet
    return ptr;
}

bool PtrStack::isEmpty() {
    return top == NULL;
}

void PtrStack::display() {
    if (top == NULL) {
        cout << "Pointer stack is empty!\n";
        return;
    }
    PtrNode* temp = top;
    cout << "Pointer Stack (top -> bottom): ";
    while (temp != NULL) {
        cout << "[" << *temp->ptr << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
