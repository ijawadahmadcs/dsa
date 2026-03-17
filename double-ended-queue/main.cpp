#include "linkedlist.h"
#include <vector>

// Deep-copy a linked list directly (no print noise from insert functions)
LinkedList* copyLinkedList(LinkedList* src) {
    LinkedList* newList = new LinkedList();
    Node* temp = src->head;
    while (temp != NULL) {
        Node* newNode = new Node(temp->data);
        if (newList->head == NULL) {
            newList->head = newNode;
            newList->tail = newNode;
        } else {
            newList->tail->next = newNode;
            newNode->prev = newList->tail;
            newList->tail = newNode;
        }
        temp = temp->next;
    }
    return newList;
}

int main() {

    vector<LinkedList*> deques;
    deques.push_back(new LinkedList());   // Deque 1
    deques.push_back(new LinkedList());   // Deque 2

    int choice, value, position, dequeChoice;

    do {
        cout<<"\nDEQUE Menu (Active Deques: "<<deques.size()<<")"<<endl;
        cout << "1.  Insert at Front" << endl;
        cout << "2.  Insert at Rear" << endl;
        cout << "3.  Insert at Position" << endl;
        cout << "4.  Delete from Front" << endl;
        cout << "5.  Delete from Rear" << endl;
        cout << "6.  Delete at Position" << endl;
        cout << "7.  Search" << endl;
        cout << "8.  Reverse " << endl;
        cout << "9.  Count Elements" << endl;
        cout << "10. Display Deque" << endl;
        cout << "11. Find Largest" << endl;
        cout << "12. Find Smallest" << endl;
        cout << "13. Get Sum" << endl;
        cout << "14. Get Average" << endl;
        cout << "15. Split Deque   " << endl;
        cout << "16. Concatenate   " << endl;
        cout << "17. Find Third Largest" << endl;
        cout << "18. Check if Deque is Empty" << endl;
        cout << "19. View Front Element" << endl;
        cout << "20. View Rear Element" << endl;
        cout << "21. Display All Deques" << endl;
        cout << "0.  Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        LinkedList* selectedDeque = nullptr;
        if ((choice >= 1 && choice <= 14) || choice == 17 || choice == 18 || choice == 19 || choice == 20) {
            cout << "Select Deque (1 to " << deques.size() << "): ";
            cin >> dequeChoice;
            if (dequeChoice < 1 || dequeChoice > (int)deques.size()) {
                cout << "Invalid deque selection!\n";
                continue;
            }
            selectedDeque = deques[dequeChoice - 1];
        }

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            selectedDeque->insertAtStart(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            selectedDeque->insertAtEnd(value);
            break;

        case 3:
            selectedDeque->insertAtPosition(value, position);
            break;

        case 4:
            selectedDeque->deleteAtStart();
            break;

        case 5:
            selectedDeque->deleteFromEnd();
            break;

        case 6:
            selectedDeque->deleteAtPosition(position);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            if (selectedDeque->search(value))
                cout << "Found!\n";
            else
                cout << "Not Found!\n";
            break;

        case 8: {
            LinkedList* reversed = copyLinkedList(selectedDeque);
            reversed->reverse();
            deques.push_back(reversed);
            cout << "Reversed copy stored as Deque " << deques.size() << ".\n";
            break;
        }

        case 9:
            cout << "Total Elements: " << selectedDeque->countNodes() << endl;
            break;

        case 10:
            selectedDeque->display();
            break;

        case 11:
            cout << "Largest: " << selectedDeque->findLargest() << endl;
            break;

        case 12:
            cout << "Smallest: " << selectedDeque->findSmallest() << endl;
            break;

        case 13:
            cout << "Sum: " << selectedDeque->getSum() << endl;
            break;

        case 14:
            cout << "Average: " << selectedDeque->getAverage() << endl;
            break;

        case 15: {
            // First half stays in the selected deque; second half becomes a new deque
            cout << "Select Deque to split (1 to " << deques.size() << "): ";
            cin >> dequeChoice;
            if (dequeChoice < 1 || dequeChoice > (int)deques.size()) {
                cout << "Invalid deque selection!\n";
                break;
            }
            cout << "Enter position to split at: ";
            cin >> position;

            LinkedList* secondPart = new LinkedList();
            deques[dequeChoice - 1]->split(position, *secondPart);
            deques.push_back(secondPart);
            cout << "Second part stored as Deque " << deques.size() << ".\n";
            break;
        }

        case 16: {
            // Concatenation result is a brand-new deque; both source deques are unchanged
            int first, second;
            cout << "Select first deque  (1 to " << deques.size() << "): ";
            cin >> first;
            cout << "Select second deque (1 to " << deques.size() << "): ";
            cin >> second;

            if (first < 1 || first > (int)deques.size() ||
                second < 1 || second > (int)deques.size()) {
                cout << "Invalid deque selection!\n";
                break;
            }
            if (first == second) {
                cout << "Cannot concatenate a deque with itself!\n";
                break;
            }

            // Deep-copy the first deque, then chain the second deque's nodes into it
            LinkedList* result = copyLinkedList(deques[first - 1]);
            LinkedList* copySecond = copyLinkedList(deques[second - 1]);
            result->concatenate(*copySecond);
            // copySecond's nodes are now owned by result; free only the shell
            delete copySecond;

            deques.push_back(result);
            cout << "Concatenated result stored as Deque " << deques.size() << ".\n";
            break;
        }

        case 17:
            cout << "Third Largest: " << selectedDeque->findThirdLargest() << endl;
            break;

        case 18:
            if (selectedDeque->countNodes() == 0)
                cout << "Deque is Empty.\n";
            else
                cout << "Deque is NOT Empty.\n";
            break;

        case 19:
            cout << "Front Element: " << selectedDeque->peekFront() << endl;
            break;

        case 20:
            cout << "Rear Element: " << selectedDeque->peekRear() << endl;
            break;

        case 21:
            cout << "\n=== All Deques (" << deques.size() << " total) ===" << endl;
            for (int i = 0; i < (int)deques.size(); i++) {
                cout << "Deque " << (i + 1) << " -> ";
                deques[i]->display();
            }
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    // Cleanup all heap-allocated deques
    for (LinkedList* dq : deques)
        delete dq;

    return 0;
}
