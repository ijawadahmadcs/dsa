#include "heap.h"

using namespace std;

Heap::Heap() {
	head = NULL;
	n = 0;
}

Heap::~Heap() {
	while (head != NULL) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
}

void Heap::insert(int orderNo, int price) {
	Order order{orderNo, price};
	Node *newNode = new Node(order);

	if (head == NULL || order.price < head->data.price) {
		newNode->next = head;
		head = newNode;
		n++;
		return;
	}

	Node *temp = head;
	while (temp->next != NULL && temp->next->data.price <= order.price)
		temp = temp->next;

	newNode->next = temp->next;
	temp->next = newNode;
	n++;
}

void Heap::del() {
	if (head == NULL) {
		cout << "Heap is empty" << endl;
		return;
	}

	Node *temp = head;
	cout << "Removed order no " << temp->data.orderNo
		 << " with price " << temp->data.price << endl;

	head = head->next;
	delete temp;
	n--;

}

void Heap::display() const {
	if (head == NULL) {
		cout << "Heap is empty" << endl;
		return;
	}

	Node *temp = head;
	while (temp != NULL) {
		cout << "Order No: " << temp->data.orderNo
			 << ", Price: " << temp->data.price << endl;
		temp = temp->next;
	}
}


