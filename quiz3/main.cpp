#include "heap.h"
using namespace std;

int main() {
	Heap platform;
	int choice;
	int orderNo;
	int price;

	while (true) {
		cout << endl;
		cout << "1. Insert order" << endl;
		cout << "2. Remove lowest price order" << endl;
		cout << "3. Display orders" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter order no: ";
			cin >> orderNo;
			cout << "Enter price: ";
			cin >> price;
			platform.insert(orderNo, price);
			break;
		case 2:
			platform.del();
			break;
		case 3:
			platform.display();
			break;
		case 4:
			return 0;
		default:
			cout << "Invalid choice" << endl;
		}
	}

	return 0;
}



