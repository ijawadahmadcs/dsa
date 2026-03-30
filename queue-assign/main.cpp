#include "queue.h"

int main() {

    int choice;

    do {
        cout << "\n----- QUEUE MENU -----\n";
        cout << "1.  Reverse Queue Using Queue Ops (Q1)\n";
        cout << "2.  Sort Deque Descending (Q2)\n";
        cout << "3.  Circular Deque Using Linked List (Q3)\n";
        cout << "4.  Check Two Queues Identical (Q4)\n";
        cout << "5.  Palindrome Check Using Deque (Q5)\n";
        cout << "6.  Call Center Using Multiple Queues (Q6)\n";
        cout << "7.  Deque Using Two Stacks (Q7)\n";
        cout << "8.  kth Largest in Queue (Q8)\n";
        cout << "9.  Queue Using Priority Queue (Q9)\n";
        cout << "10. Split Two Deques into Three Equal Deques (Q10)\n";
        cout << "11. Split Two Queues into Three Queues (Q11)\n";
        cout << "12. Sort Two Deques and Concat from Rear (Q12)\n";
        cout << "13. Print Rear, Front and Middle of Queue (Q13)\n";
        cout << "14. Print Index 1,3,6,10... Values from Queue (Q14)\n";
        cout << "15. Remove Center till Deque Size 3 (Q15)\n";
        cout << "0.  Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Q1 – Reverse queue using only queue operations
        if (choice == 1) {
            Queue q;
            int sub, val;
            do {
                cout << "\n-- Q1: Reverse Queue --\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Reverse\n";
                cout << "4. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    q.enqueue(val);
                    cout << "Enqueued " << val << ".\n";
                    break;
                case 2:
                    val = q.dequeue();
                    if (val != -1) cout << "Dequeued " << val << ".\n";
                    break;
                case 3:
                    reverseQueueUsingOps(q);
                    cout << "Queue reversed using queue operations only.\n";
                    break;
                case 4:
                    q.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q2 – Sort deque descending
        else if (choice == 2) {
            Deque dq;
            int sub, val;
            do {
                cout << "\n-- Q2: Sort Deque Descending --\n";
                cout << "1. Insert Front\n";
                cout << "2. Insert Rear\n";
                cout << "3. Delete Front\n";
                cout << "4. Delete Rear\n";
                cout << "5. Sort Descending\n";
                cout << "6. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    dq.insertFront(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    dq.insertRear(val);
                    break;
                case 3:
                    val = dq.deleteFront();
                    if (val != -1) cout << "Deleted front: " << val << "\n";
                    break;
                case 4:
                    val = dq.deleteRear();
                    if (val != -1) cout << "Deleted rear: " << val << "\n";
                    break;
                case 5:
                    sortDequeDescending(dq);
                    break;
                case 6:
                    dq.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q3 – Circular deque using linked list
        else if (choice == 3) {
            CircularDeque cdq;
            int sub, val;
            do {
                cout << "\n-- Q3: Circular Deque --\n";
                cout << "1. Insert Front\n";
                cout << "2. Insert Rear\n";
                cout << "3. Delete Front\n";
                cout << "4. Delete Rear\n";
                cout << "5. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    cdq.insertFront(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    cdq.insertRear(val);
                    break;
                case 3:
                    val = cdq.deleteFront();
                    if (val != -1) cout << "Deleted front: " << val << "\n";
                    break;
                case 4:
                    val = cdq.deleteRear();
                    if (val != -1) cout << "Deleted rear: " << val << "\n";
                    break;
                case 5:
                    cdq.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q4 – Check two queues identical
        else if (choice == 4) {
            Queue q1, q2;
            int sub, val;
            do {
                cout << "\n-- Q4: Identical Queues --\n";
                cout << "1. Enqueue to Queue 1\n";
                cout << "2. Enqueue to Queue 2\n";
                cout << "3. Display Queue 1\n";
                cout << "4. Display Queue 2\n";
                cout << "5. Check Identical\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    q1.enqueue(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    q2.enqueue(val);
                    break;
                case 3:
                    q1.display();
                    break;
                case 4:
                    q2.display();
                    break;
                case 5:
                    if (areQueuesIdentical(q1, q2))
                        cout << "Queues are IDENTICAL.\n";
                    else
                        cout << "Queues are NOT identical.\n";
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q5 – Palindrome check ignoring non-alphanumeric
        else if (choice == 5) {
            string text;
            cin.ignore();
            cout << "Enter string: ";
            getline(cin, text);

            if (isValidPalindromeUsingDeque(text))
                cout << "Valid palindrome (ignoring non-alphanumeric).\n";
            else
                cout << "Not a palindrome.\n";
        }

        // Q6 – Call center simulation
        else if (choice == 6) {
            CallCenter cc;
            int sub, id, pr;
            do {
                cout << "\n-- Q6: Call Center --\n";
                cout << "1. Add Inquiry\n";
                cout << "2. Process Next Inquiry\n";
                cout << "3. Display All Queues\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter inquiry id: ";
                    cin >> id;
                    cout << "Enter priority (3=Urgent, 2=Normal, 1=Low): ";
                    cin >> pr;
                    cc.addCall(id, pr);
                    break;
                case 2:
                    cc.processCall();
                    break;
                case 3:
                    cc.displayAll();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q7 – Deque using two stacks
        else if (choice == 7) {
            TwoStackDeque tdq;
            int sub, val;
            do {
                cout << "\n-- Q7: Deque Using Two Stacks --\n";
                cout << "1. Insert Front\n";
                cout << "2. Insert Rear\n";
                cout << "3. Delete Front\n";
                cout << "4. Delete Rear\n";
                cout << "5. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    tdq.insertFront(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    tdq.insertRear(val);
                    break;
                case 3:
                    tdq.deleteFront();
                    break;
                case 4:
                    tdq.deleteRear();
                    break;
                case 5:
                    tdq.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q8 – kth largest in queue
        else if (choice == 8) {
            Queue q;
            int sub, val, k;
            do {
                cout << "\n-- Q8: kth Largest in Queue --\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Find kth Largest\n";
                cout << "4. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    q.enqueue(val);
                    break;
                case 2:
                    val = q.dequeue();
                    if (val != -1) cout << "Dequeued " << val << "\n";
                    break;
                case 3:
                    cout << "Enter k: ";
                    cin >> k;
                    val = kthLargestInQueue(q, k);
                    if (val != -1) cout << k << "th largest = " << val << "\n";
                    break;
                case 4:
                    q.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q9 – Queue using priority queue
        else if (choice == 9) {
            PriorityQueueLL pq;
            int sub, val, pr;
            do {
                cout << "\n-- Q9: Priority Queue --\n";
                cout << "1. Enqueue (value, priority)\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    cout << "Enter priority: ";
                    cin >> pr;
                    pq.enqueue(val, pr);
                    break;
                case 2:
                    val = pq.dequeue();
                    if (val != -1) cout << "Dequeued: " << val << "\n";
                    break;
                case 3:
                    pq.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q10 – Split two deques into three equal
        else if (choice == 10) {
            Deque d1, d2, a, b, c;
            int sub, val;
            do {
                cout << "\n-- Q10: Split Two Deques into Three Equal --\n";
                cout << "1. Insert Rear in Deque 1\n";
                cout << "2. Insert Rear in Deque 2\n";
                cout << "3. Display Deque 1\n";
                cout << "4. Display Deque 2\n";
                cout << "5. Split\n";
                cout << "6. Display Result A/B/C\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    d1.insertRear(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    d2.insertRear(val);
                    break;
                case 3:
                    d1.display();
                    break;
                case 4:
                    d2.display();
                    break;
                case 5:
                    splitTwoDequesIntoThreeEqual(d1, d2, a, b, c);
                    break;
                case 6:
                    cout << "Deque A: "; a.display();
                    cout << "Deque B: "; b.display();
                    cout << "Deque C: "; c.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q11 – Split two queues into 3 with size rule
        else if (choice == 11) {
            Queue q1, q2, a, b, c;
            int sub, val;
            do {
                cout << "\n-- Q11: Split Two Queues into Three --\n";
                cout << "1. Enqueue in Queue 1\n";
                cout << "2. Enqueue in Queue 2\n";
                cout << "3. Display Queue 1\n";
                cout << "4. Display Queue 2\n";
                cout << "5. Split with size(C)=size(A)+size(B)\n";
                cout << "6. Display Result A/B/C\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    q1.enqueue(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    q2.enqueue(val);
                    break;
                case 3:
                    q1.display();
                    break;
                case 4:
                    q2.display();
                    break;
                case 5:
                    splitTwoQueuesWithSumRule(q1, q2, a, b, c);
                    break;
                case 6:
                    cout << "Queue A: "; a.display();
                    cout << "Queue B: "; b.display();
                    cout << "Queue C: "; c.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q12 – Sort two deques and concatenate from rear
        else if (choice == 12) {
            Deque d1, d2, result;
            int sub, val;
            do {
                cout << "\n-- Q12: Sort + Concat from Rear --\n";
                cout << "1. Insert Rear in Deque 1\n";
                cout << "2. Insert Rear in Deque 2\n";
                cout << "3. Display Deque 1\n";
                cout << "4. Display Deque 2\n";
                cout << "5. Sort and Concat\n";
                cout << "6. Display Result\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    d1.insertRear(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    d2.insertRear(val);
                    break;
                case 3:
                    d1.display();
                    break;
                case 4:
                    d2.display();
                    break;
                case 5:
                    sortAndConcatFromRear(d1, d2, result);
                    break;
                case 6:
                    result.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q13 – Print front/rear/middle
        else if (choice == 13) {
            Queue q;
            int sub, val;
            do {
                cout << "\n-- Q13: Front Rear Middle --\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "4. Print Front Rear Middle\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    q.enqueue(val);
                    break;
                case 2:
                    val = q.dequeue();
                    if (val != -1) cout << "Dequeued " << val << "\n";
                    break;
                case 3:
                    q.display();
                    break;
                case 4:
                    printFrontRearMiddle(q);
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q14 – Print values at triangular indices
        else if (choice == 14) {
            Queue q;
            int sub, val;
            do {
                cout << "\n-- Q14: Triangular Index Values --\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "4. Print Values\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    q.enqueue(val);
                    break;
                case 2:
                    val = q.dequeue();
                    if (val != -1) cout << "Dequeued " << val << "\n";
                    break;
                case 3:
                    q.display();
                    break;
                case 4:
                    printTriangularIndexValues(q);
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q15 – Remove center until size 3
        else if (choice == 15) {
            Deque dq;
            int sub, val;
            do {
                cout << "\n-- Q15: Remove Center till Size 3 --\n";
                cout << "1. Insert Rear\n";
                cout << "2. Delete Front\n";
                cout << "3. Display\n";
                cout << "4. Process\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    dq.insertRear(val);
                    break;
                case 2:
                    val = dq.deleteFront();
                    if (val != -1) cout << "Deleted front: " << val << "\n";
                    break;
                case 3:
                    dq.display();
                    break;
                case 4:
                    shrinkDequeToThreeByRemovingCenter(dq);
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    cout << "Exiting program...\n";
    return 0;
}
