#include "linkedlist.h"
#include <vector>

// Deep-copy a circular linked list (head, last->next == head)
LinkedList* copyLinkedList(LinkedList* src) {
    LinkedList* newList = new LinkedList();
    if (src->head == NULL) return newList;
    Node* temp = src->head;
    Node* firstNew = NULL;
    Node* prevNew = NULL;
    do {
        Node* newNode = new Node(temp->data);
        if (firstNew == NULL) {
            firstNew = newNode;
            newList->head = newNode;
        } else {
            prevNew->next = newNode;
        }
        prevNew = newNode;
        temp = temp->next;
    } while (temp != src->head);
    prevNew->next = firstNew;   // close the circle
    return newList;
}

int main() {

    vector<LinkedList*> lists;
    lists.push_back(new LinkedList());   // List 1
    lists.push_back(new LinkedList());   // List 2
    int choice, value, position, listChoice;

    do {
        cout << "\n=== CIRCULAR LINKED LIST MENU (Active Lists: " << lists.size() << ") ===" << endl;
        cout << "1.  Insert at Beginning\n";
        cout << "2.  Insert at End\n";
        cout << "3.  Insert at Position\n";
        cout << "4.  Delete at Beginning\n";
        cout << "5.  Delete from End\n";
        cout << "6.  Delete at Position\n";
        cout << "7.  Search Element\n";
        cout << "8.  Reverse List      (creates new list)\n";
        cout << "9.  Count Nodes\n";
        cout << "10. Display List\n";
        cout << "11. Find Largest\n";
        cout << "12. Find Smallest\n";
        cout << "13. Get Sum\n";
        cout << "14. Get Average\n";
        cout << "15. Split List        (second part becomes new list)\n";
        cout << "16. Concatenate Lists  (result stored as new list)\n";
        cout << "17. Find Third Largest\n";
        cout << "18. Check if List is Empty\n";
        cout << "19. Copy to New List\n";
        cout << "20. Display All Lists\n";
        cout << "21. Search and Replace\n";
        cout << "0.  Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        LinkedList* selectedList = nullptr;
        if ((choice >= 1 && choice <= 14) || choice == 17 || choice == 18 || choice == 19 || choice == 21) {
            cout << "Select List (1 to " << lists.size() << "): ";
            cin >> listChoice;
            if (listChoice < 1 || listChoice > (int)lists.size()) {
                cout << "Invalid list selection!\n";
                continue;
            }
            selectedList = lists[listChoice - 1];
        }

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            selectedList->insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            selectedList->insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value and position: ";
            cin >> value >> position;
            selectedList->insertAtPosition(value, position);
            break;

        case 4:
            selectedList->deleteAtBeginning();
            break;

        case 5:
            selectedList->deleteFromEnd();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> position;
            selectedList->deleteAtPosition(position);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            if (selectedList->search(value))
                cout << "Found!\n";
            else
                cout << "Not Found!\n";
            break;

        case 8: {
            LinkedList* reversed = copyLinkedList(selectedList);
            reversed->reverse();
            lists.push_back(reversed);
            cout << "Reversed copy stored as List " << lists.size() << ".\n";
            break;
        }

        case 9:
            cout << "Total Nodes: " << selectedList->countNodes() << endl;
            break;

        case 10:
            selectedList->display();
            break;

        case 11:
            cout << "Largest: " << selectedList->findLargest() << endl;
            break;

        case 12:
            cout << "Smallest: " << selectedList->findSmallest() << endl;
            break;

        case 13:
            cout << "Sum: " << selectedList->getSum() << endl;
            break;

        case 14:
            cout << "Average: " << selectedList->getAverage() << endl;
            break;

        case 15: {
            cout << "Select List to split (1 to " << lists.size() << "): ";
            cin >> listChoice;
            if (listChoice < 1 || listChoice > (int)lists.size()) {
                cout << "Invalid list selection!\n";
                break;
            }
            cout << "Enter position to split at: ";
            cin >> position;
            LinkedList* secondPart = new LinkedList();
            lists[listChoice - 1]->split(position, *secondPart);
            lists.push_back(secondPart);
            cout << "Second part stored as List " << lists.size() << ".\n";
            break;
        }

        case 16: {
            int first, second;
            cout << "Select first list  (1 to " << lists.size() << "): ";
            cin >> first;
            cout << "Select second list (1 to " << lists.size() << "): ";
            cin >> second;
            if (first < 1 || first > (int)lists.size() ||
                second < 1 || second > (int)lists.size()) {
                cout << "Invalid list selection!\n";
                break;
            }
            if (first == second) {
                cout << "Cannot concatenate a list with itself!\n";
                break;
            }
            LinkedList* result = copyLinkedList(lists[first - 1]);
            LinkedList* copySecond = copyLinkedList(lists[second - 1]);
            result->concatenate(*copySecond);
            delete copySecond;
            lists.push_back(result);
            cout << "Concatenated result stored as List " << lists.size() << ".\n";
            break;
        }

        case 17:
            cout << "Third Largest: " << selectedList->findThirdLargest() << endl;
            break;

        case 18:
            if (selectedList->countNodes() == 0)
                cout << "List is Empty.\n";
            else
                cout << "List is NOT Empty.\n";
            break;

        case 19: {
            LinkedList* copiedList = copyLinkedList(selectedList);
            lists.push_back(copiedList);
            cout << "Copy stored as List " << lists.size() << ".\n";
            break;
        }

        case 20:
            cout << "\n=== All Lists (" << lists.size() << " total) ===" << endl;
            for (int i = 0; i < (int)lists.size(); i++) {
                cout << "List " << (i + 1) << " -> ";
                lists[i]->display();
            }
            break;

        case 21:
            cout << "Enter value to search: ";
            cin >> value;
            selectedList->searchAndReplace(value);
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    for (LinkedList* l : lists)
        delete l;

    return 0;
}
