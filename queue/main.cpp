#include "linkedlist.h"
#include <vector>

// Deep-copy a singly linked queue (head only, next only)
LinkedList* copyLinkedList(LinkedList* src) {
    LinkedList* newList = new LinkedList();
    Node* temp = src->head;
    Node* tail = NULL;
    while (temp != NULL) {
        Node* newNode = new Node(temp->data);
        if (newList->head == NULL) {
            newList->head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        temp = temp->next;
    }
    return newList;
}

int main() {

    vector<LinkedList*> queues;
    queues.push_back(new LinkedList());   // Queue 1
    queues.push_back(new LinkedList());   // Queue 2
    int choice, value, position, queueChoice;

    do {
        cout << "\n QUEUE Menu (Active Queues: " << queues.size() << ") " << endl;
        cout << "1.  Insert at Rear" << endl;
        cout << "2.  Insert at Front" << endl;
        cout << "3.  Insert at Position" << endl;
        cout << "4.  Delete from Front" << endl;
        cout << "5.  Delete from Rear" << endl;
        cout << "6.  Delete at Position" << endl;
        cout << "7.  Search" << endl;
        cout << "8.  Reverse" << endl;
        cout << "9.  Count Elements" << endl;
        cout << "10. Display Queue" << endl;
        cout << "11. Find Largest" << endl;
        cout << "12. Find Smallest" << endl;
        cout << "13. Get Sum" << endl;
        cout << "14. Get Average" << endl;
        cout << "15. Split Queue" << endl;
        cout << "16. Concatenate" << endl;
        cout << "17. Find Third Largest" << endl;
        cout << "18. Check if Queue is Empty" << endl;
        cout << "19. View Front Element" << endl;
        cout << "20. Display All Queues" << endl;
        cout << "0.  Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        LinkedList* selectedQueue = nullptr;
        if ((choice >= 1 && choice <= 14) || choice == 17 || choice == 18 || choice == 19) {
            cout << "Select Queue (1 to " << queues.size() << "): ";
            cin >> queueChoice;
            if (queueChoice < 1 || queueChoice > (int)queues.size()) {
                cout << "Invalid queue selection!\n";
                continue;
            }
            selectedQueue = queues[queueChoice - 1];
        }

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            selectedQueue->insertAtEnd(value);
            break;

        case 2:
            selectedQueue->insertAtStart(value);
            break;

        case 3:
            selectedQueue->insertAtPosition(value, position);
            break;

        case 4:
            selectedQueue->deleteAtStart();
            break;

        case 5:
            selectedQueue->deleteFromEnd();
            break;

        case 6:
            selectedQueue->deleteAtPosition(position);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            if (selectedQueue->search(value))
                cout << "Found!\n";
            else
                cout << "Not Found!\n";
            break;

        case 8: {
            LinkedList* reversed = copyLinkedList(selectedQueue);
            reversed->reverse();
            queues.push_back(reversed);
            cout << "Reversed copy stored as Queue " << queues.size() << ".\n";
            break;
        }

        case 9:
            cout << "Total Elements: " << selectedQueue->countNodes() << endl;
            break;

        case 10:
            selectedQueue->display();
            break;

        case 11:
            cout << "Largest: " << selectedQueue->findLargest() << endl;
            break;

        case 12:
            cout << "Smallest: " << selectedQueue->findSmallest() << endl;
            break;

        case 13:
            cout << "Sum: " << selectedQueue->getSum() << endl;
            break;

        case 14:
            cout << "Average: " << selectedQueue->getAverage() << endl;
            break;

        case 15: {
            cout << "Select Queue to split (1 to " << queues.size() << "): ";
            cin >> queueChoice;
            if (queueChoice < 1 || queueChoice > (int)queues.size()) {
                cout << "Invalid queue selection!\n";
                break;
            }
            cout << "Enter position to split at: ";
            cin >> position;
            LinkedList* secondPart = new LinkedList();
            queues[queueChoice - 1]->split(position, *secondPart);
            queues.push_back(secondPart);
            cout << "Second part stored as Queue " << queues.size() << ".\n";
            break;
        }

        case 16: {
            int first, second;
            cout << "Select first queue  (1 to " << queues.size() << "): ";
            cin >> first;
            cout << "Select second queue (1 to " << queues.size() << "): ";
            cin >> second;
            if (first < 1 || first > (int)queues.size() ||
                second < 1 || second > (int)queues.size()) {
                cout << "Invalid queue selection!\n";
                break;
            }
            if (first == second) {
                cout << "Cannot concatenate a queue with itself!\n";
                break;
            }
            LinkedList* result = copyLinkedList(queues[first - 1]);
            LinkedList* copySecond = copyLinkedList(queues[second - 1]);
            result->concatenate(*copySecond);
            delete copySecond;
            queues.push_back(result);
            cout << "Concatenated result stored as Queue " << queues.size() << ".\n";
            break;
        }

        case 17:
            cout << "Third Largest: " << selectedQueue->findThirdLargest() << endl;
            break;

        case 18:
            if (selectedQueue->countNodes() == 0)
                cout << "Queue is Empty.\n";
            else
                cout << "Queue is NOT Empty.\n";
            break;

        case 19:
            cout << "Front Element: " << selectedQueue->peek() << endl;
            break;

        case 20:
            cout << "\n All Queues (" << queues.size() << " total) " << endl;
            for (int i = 0; i < (int)queues.size(); i++) {
                cout << "Queue " << (i + 1) << " -> ";
                queues[i]->display();
            }
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    for (LinkedList* q : queues)
        delete q;

    return 0;
}
