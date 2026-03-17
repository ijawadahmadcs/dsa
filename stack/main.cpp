#include "linkedlist.h"
#include <vector>

// Deep-copy a singly linked stack (head only, next only)
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

    vector<LinkedList*> stacks;
    stacks.push_back(new LinkedList());   // Stack 1
    stacks.push_back(new LinkedList());   // Stack 2
    int choice, value, position, stackChoice;

    do {
        cout << "\n=== STACK MENU (Active Stacks: " << stacks.size() << ") ===" << endl;
        cout << "1.  Insert at Top" << endl;
        cout << "2.  Insert at End" << endl;
        cout << "3.  Insert at Position" << endl;
        cout << "4.  Delete from Top" << endl;
        cout << "5.  Delete from End" << endl;
        cout << "6.  Delete at Position" << endl;
        cout << "7.  Search" << endl;
        cout << "8.  Reverse           (creates new stack)" << endl;
        cout << "9.  Count Elements" << endl;
        cout << "10. Display Stack" << endl;
        cout << "11. Find Largest" << endl;
        cout << "12. Find Smallest" << endl;
        cout << "13. Get Sum" << endl;
        cout << "14. Get Average" << endl;
        cout << "15. Split Stack       (second part becomes new stack)" << endl;
        cout << "16. Concatenate       (result stored as new stack)" << endl;
        cout << "17. Find Third Largest" << endl;
        cout << "18. Check if Stack is Empty" << endl;
        cout << "19. View Top Element" << endl;
        cout << "20. Display All Stacks" << endl;
        cout << "0.  Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        LinkedList* selectedStack = nullptr;
        if ((choice >= 1 && choice <= 14) || choice == 17 || choice == 18 || choice == 19) {
            cout << "Select Stack (1 to " << stacks.size() << "): ";
            cin >> stackChoice;
            if (stackChoice < 1 || stackChoice > (int)stacks.size()) {
                cout << "Invalid stack selection!\n";
                continue;
            }
            selectedStack = stacks[stackChoice - 1];
        }

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            selectedStack->insertAtStart(value);
            break;

        case 2:
            selectedStack->insertAtEnd(value);
            break;

        case 3:
            selectedStack->insertAtPosition(value, position);
            break;

        case 4:
            selectedStack->deleteAtStart();
            break;

        case 5:
            selectedStack->deleteFromEnd();
            break;

        case 6:
            selectedStack->deleteAtPosition(position);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            if (selectedStack->search(value))
                cout << "Found!\n";
            else
                cout << "Not Found!\n";
            break;

        case 8: {
            LinkedList* reversed = copyLinkedList(selectedStack);
            reversed->reverse();
            stacks.push_back(reversed);
            cout << "Reversed copy stored as Stack " << stacks.size() << ".\n";
            break;
        }

        case 9:
            cout << "Total Elements: " << selectedStack->countNodes() << endl;
            break;

        case 10:
            selectedStack->display();
            break;

        case 11:
            cout << "Largest: " << selectedStack->findLargest() << endl;
            break;

        case 12:
            cout << "Smallest: " << selectedStack->findSmallest() << endl;
            break;

        case 13:
            cout << "Sum: " << selectedStack->getSum() << endl;
            break;

        case 14:
            cout << "Average: " << selectedStack->getAverage() << endl;
            break;

        case 15: {
            cout << "Select Stack to split (1 to " << stacks.size() << "): ";
            cin >> stackChoice;
            if (stackChoice < 1 || stackChoice > (int)stacks.size()) {
                cout << "Invalid stack selection!\n";
                break;
            }
            cout << "Enter position to split at: ";
            cin >> position;
            LinkedList* secondPart = new LinkedList();
            stacks[stackChoice - 1]->split(position, *secondPart);
            stacks.push_back(secondPart);
            cout << "Second part stored as Stack " << stacks.size() << ".\n";
            break;
        }

        case 16: {
            int first, second;
            cout << "Select first stack  (1 to " << stacks.size() << "): ";
            cin >> first;
            cout << "Select second stack (1 to " << stacks.size() << "): ";
            cin >> second;
            if (first < 1 || first > (int)stacks.size() ||
                second < 1 || second > (int)stacks.size()) {
                cout << "Invalid stack selection!\n";
                break;
            }
            if (first == second) {
                cout << "Cannot concatenate a stack with itself!\n";
                break;
            }
            LinkedList* result = copyLinkedList(stacks[first - 1]);
            LinkedList* copySecond = copyLinkedList(stacks[second - 1]);
            result->concatenate(*copySecond);
            delete copySecond;
            stacks.push_back(result);
            cout << "Concatenated result stored as Stack " << stacks.size() << ".\n";
            break;
        }

        case 17:
            cout << "Third Largest: " << selectedStack->findThirdLargest() << endl;
            break;

        case 18:
            if (selectedStack->countNodes() == 0)
                cout << "Stack is Empty.\n";
            else
                cout << "Stack is NOT Empty.\n";
            break;

        case 19:
            cout << "Top Element: " << selectedStack->peek() << endl;
            break;

        case 20:
            cout << "\n=== All Stacks (" << stacks.size() << " total) ===" << endl;
            for (int i = 0; i < (int)stacks.size(); i++) {
                cout << "Stack " << (i + 1) << " -> ";
                stacks[i]->display();
            }
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    for (LinkedList* st : stacks)
        delete st;

    return 0;
}
