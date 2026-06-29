#ifndef HEAP_H
#define HEAP_H

#include <iostream>

struct Order {
	int orderNo;
	int price;
};

struct Node {
	Order data;
	Node *next;

	Node(const Order &value) : data(value), next(NULL) {}
};

class Heap {
private:
	Node *head;
	int n;

public:
	Heap();
	~Heap();

	void insert(int orderNo, int price);
	void del();
	void display() const;
};

#endif