#include<iostream>
#include "heap.h"

void insert(int item)
{
    node *temp = new node;
    temp->info = item;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
        return;
    }
    if (item > start->info)
    {
        temp->next = start;
        start = temp;
        return;
    }
    node *ptr = start;

    while (ptr->next != NULL && ptr->next->info > item)
    {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}


void del(int item)
{
    if (start == NULL)
    {
        cout << "Heap empty\n";
        return;
    }

    node *ptr = start;
    node *prev = NULL;

    // Step 1: find node with given value
    node *target = NULL;
    node *targetPrev = NULL;

    while (ptr != NULL)
    {
        if (ptr->info == item)
        {
            target = ptr;
            targetPrev = prev;
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    if (target == NULL)
    {
        cout << "Item not found\n";
        return;
    }

    // Step 2: if only one node
    if (start->next == NULL)
    {
        delete start;
        start = NULL;
        return;
    }

    // Step 3: find last node
    node *last = start;
    node *lastPrev = NULL;

    while (last->next != NULL)
    {
        lastPrev = last;
        last = last->next;
    }

    // Step 4: replace target with last node value
    target->info = last->info;

    // Step 5: delete last node
    if (lastPrev != NULL)
        lastPrev->next = NULL;
    else
        start = NULL;

    delete last;

    // Step 6: optional "heap-style adjustment"
    node *current = start;

    while (current != NULL)
    {
        node *largest = current;
        node *child = current->next;

        if (child != NULL && child->info > largest->info)
            largest = child;

        if (largest == current)
            break;

        int temp = current->info;
        current->info = largest->info;
        largest->info = temp;

        current = largest;
    }
}


void display()
{
    node *ptr;

    if (start == NULL)
    {
        cout << "Heap empty\n";
        return;
    }

    ptr = start;

    while (ptr != NULL)
    {
        cout << ptr->info << " ";
        ptr = ptr->next;
    }

    cout << endl;
}


void sort()
{
    if (start == NULL)
    {
        cout << "Heap empty\n";
        return;
    }

    node *tempStart = NULL;   // copy list head
    node *ptr = start;

    // Step 1: create a COPY of original list (to protect it)
    while (ptr != NULL)
    {
        node *temp = new node;
        temp->info = ptr->info;
        temp->next = tempStart;
        tempStart = temp;

        ptr = ptr->next;
    }

    node *sorted = NULL;

    // Step 2: repeatedly take max (front of tempStart)
    while (tempStart != NULL)
    {
        node *maxNode = tempStart;
        node *maxPrev = NULL;
        node *prev = NULL;
        node *curr = tempStart;

        // find max node (since copy is descending, it's already at start)
        maxNode = tempStart;
        maxPrev = NULL;

        // remove maxNode from tempStart
        if (maxPrev == NULL)
            tempStart = tempStart->next;
        else
            maxPrev->next = maxNode->next;

        // Step 3: insert into NEW sorted list in ascending order
        node *newNode = new node;
        newNode->info = maxNode->info;
        newNode->next = NULL;

        if (sorted == NULL || sorted->info >= newNode->info)
        {
            newNode->next = sorted;
            sorted = newNode;
        }
        else
        {
            node *p = sorted;

            while (p->next != NULL && p->next->info < newNode->info)
            {
                p = p->next;
            }

            newNode->next = p->next;
            p->next = newNode;
        }

        delete maxNode;
    }

    // Step 4: display sorted list
    cout << "Ascending order: ";

    node *p = sorted;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }

    cout << endl;

    // Step 5: free sorted list memory
    while (sorted != NULL)
    {
        node *temp = sorted;
        sorted = sorted->next;
        delete temp;
    }
}


void displayRight()
{
    if (start == NULL)
    {
        cout << "Heap empty\n";
        return;
    }

    node *ptr = start;
    int pos = 1;

    cout << "Right side nodes: ";

    while (ptr != NULL)
    {
        if (pos % 2 == 0)   // even position = right side
        {
            cout << ptr->info << " ";
        }

        ptr = ptr->next;
        pos++;
    }

    cout << endl;
}


void displayLeft()
{
    if (start == NULL)
    {
        cout << "Heap empty\n";
        return;
    }

    node *ptr = start;
    int pos = 1;

    cout << "Left side nodes: ";

    while (ptr != NULL)
    {
        if (pos % 2 != 0)   // odd position = left side
        {
            cout << ptr->info << " ";
        }
        
        ptr = ptr->next;
        pos++;
    }

    cout << endl;
}


void checkNodeType(int item)
{
    if (start == NULL)
    {
        cout << "Heap empty\n";
        return;
    }

    node *ptr = start;

    while (ptr != NULL)
    {
        if (ptr->info == item)
        {
            // Leaf node
            if (ptr->next == NULL)
            {
                cout << item << " is a LEAF node\n";
            }
            // One child
            else if (ptr->next->next == NULL)
            {
                cout << item << " has ONE child node\n";
            }
            // Two child (conceptual)
            else
            {
                cout << item << " has TWO child nodes\n";
            }
            return;
        }

        ptr = ptr->next;
    }

    cout << "Node not found\n";
}


void findNeighbor(int item)
{
    if (start == NULL)
    {
        cout << "Heap empty\n";
        return;
    }

    node *ptr = start;

    while (ptr != NULL)
    {
        if (ptr->info == item)
        {
            // Predecessor
            if (ptr == start)
                cout << "Predecessor: None (first node)\n";
            else
            {
                node *prev = start;
                while (prev->next != ptr)
                    prev = prev->next;

                cout << "Predecessor: " << prev->info << endl;
            }

            // Successor
            if (ptr->next == NULL)
                cout << "Successor: None (last node)\n";
            else
                cout << "Successor: " << ptr->next->info << endl;

            return;
        }

        ptr = ptr->next;
    }

    cout << "Node not found\n";
}


int countNodes()
{
    if (start == NULL)
        return 0;

    int count = 0;
    node *ptr = start;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}


void findLargestAndSmallest()
{
    if (start == NULL)
    {
        cout << "Heap empty\n";
        return;
    }

    // Largest node (first node)
    cout << "Largest node: " << start->info << endl;

    // Find smallest node (last node)
    node *ptr = start;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    cout << "Smallest node: " << ptr->info << endl;
}