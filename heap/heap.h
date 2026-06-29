#ifndef HEAP_H
#define HEAP_H

#include<iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};

extern node *start;

// Functions
void insert(int item);
void del(int item);
void display();
void sort();
void displayLeft();
void displayRight();
void checkNodeType(int item);
void findNeighbor(int item);
void findLargestAndSmallest();   // NEW
int countNodes();                // NEW (optional but useful)

#endif