#include "stack.h"

int main() {

    int choice;

    do {
        cout << "\n----- STACK MENU -----\n";
        cout << "1.  Two Stacks in One List (Q1)\n";
        cout << "2.  Even/Odd Stacks (Q2)\n";
        cout << "3.  Next Greater Element (Q3)\n";
        cout << "4.  Constant-Size Stack (Q4)\n";
        cout << "5.  Sort Stack Using Two Stacks (Q5)\n";
        cout << "6.  Palindrome Check (Q6)\n";
        cout << "7.  Copy a Stack (Q7)\n";
        cout << "8.  Balanced Brackets Check (Q8)\n";
        cout << "9.  Remove Duplicates (Q9)\n";
        cout << "10. Intersection of Two Stacks (Q10)\n";
        cout << "11. Subset Check (Q11)\n";
        cout << "12. Swap Top Two Elements (Q12)\n";
        cout << "13. Stack of Pointers (Q13)\n";
        cout << "0.  Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Q1 – Two stacks in one linked list
        if (choice == 1) {
            TwoStack ts;
            int sub, val;
            do {
                cout << "\n-- Q1: Two Stacks --\n";
                cout << "1. Push to Stack 1\n";
                cout << "2. Push to Stack 2\n";
                cout << "3. Pop from Stack 1\n";
                cout << "4. Pop from Stack 2\n";
                cout << "5. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    ts.push1(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    ts.push2(val);
                    break;
                case 3:
                    ts.pop1();
                    break;
                case 4:
                    ts.pop2();
                    break;
                case 5:
                    ts.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q2 – Even/Odd stacks
        else if (choice == 2) {
            EvenOddStack eos;
            int sub, val;
            do {
                cout << "\n-- Q2: Even/Odd Stacks --\n";
                cout << "1. Push (auto-routes to Even or Odd)\n";
                cout << "2. Pop from Even Stack\n";
                cout << "3. Pop from Odd Stack\n";
                cout << "4. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    eos.push(val);
                    break;
                case 2:
                    eos.popEven();
                    break;
                case 3:
                    eos.popOdd();
                    break;
                case 4:
                    eos.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q3 – Next greater element
        else if (choice == 3) {
            Stack s;
            int sub, val;
            do {
                cout << "\n-- Q3: Next Greater Element --\n";
                cout << "1. Push\n";
                cout << "2. Display Stack\n";
                cout << "3. Find Next Greater for Each Element\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    s.push(val);
                    cout << "Pushed " << val << ".\n";
                    break;
                case 2:
                    s.display();
                    break;
                case 3:
                    findNextGreater(s);
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q4 – Constant-size stack
        else if (choice == 4) {
            int cap;
            cout << "Enter stack capacity: ";
            cin >> cap;
            ConstStack cs(cap);
            int sub, val;
            do {
                cout << "\n-- Q4: Constant-Size Stack (capacity = " << cap << ") --\n";
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Peek\n";
                cout << "4. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    cs.push(val);
                    break;
                case 2:
                    cs.pop();
                    break;
                case 3:
                    cout << "Top: " << cs.peek() << "\n";
                    break;
                case 4:
                    cs.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q5 – Sort stack using two stacks
        else if (choice == 5) {
            Stack s;
            int sub, val;
            do {
                cout << "\n-- Q5: Sort Stack --\n";
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Sort\n";
                cout << "4. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    s.push(val);
                    cout << "Pushed " << val << ".\n";
                    break;
                case 2:
                    val = s.pop();
                    if (val != -1) cout << "Popped " << val << ".\n";
                    break;
                case 3:
                    sortUsingTwoStacks(s);
                    break;
                case 4:
                    s.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q6 – Palindrome check
        else if (choice == 6) {
            string str;
            cout << "Enter string to check: ";
            cin >> str;
            if (isPalindrome(str))
                cout << "\"" << str << "\" IS a palindrome.\n";
            else
                cout << "\"" << str << "\" is NOT a palindrome.\n";
        }

        // Q7 – Copy a stack
        else if (choice == 7) {
            Stack* original = new Stack();
            int sub, val;
            Stack* copiedStack = NULL;

            do {
                cout << "\n-- Q7: Copy Stack --\n";
                cout << "1. Push to Original\n";
                cout << "2. Display Original\n";
                cout << "3. Copy Stack\n";
                cout << "4. Display Copied Stack\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    original->push(val);
                    cout << "Pushed " << val << ".\n";
                    break;
                case 2:
                    original->display();
                    break;
                case 3:
                    if (copiedStack != NULL) delete copiedStack;
                    copiedStack = copyStack(original);
                    break;
                case 4:
                    if (copiedStack == NULL)
                        cout << "No copy made yet!\n";
                    else
                        copiedStack->display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);

            delete original;
            if (copiedStack != NULL) delete copiedStack;
        }

        // Q8 – Balanced brackets
        else if (choice == 8) {
            string expr;
            cout << "Enter bracket expression: ";
            cin >> expr;
            if (isBalanced(expr))
                cout << "\"" << expr << "\" is BALANCED.\n";
            else
                cout << "\"" << expr << "\" is NOT balanced.\n";
        }

        // Q9 – Remove duplicates
        else if (choice == 9) {
            Stack s;
            int sub, val;
            do {
                cout << "\n-- Q9: Remove Duplicates --\n";
                cout << "1. Push\n";
                cout << "2. Remove Duplicates\n";
                cout << "3. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    s.push(val);
                    cout << "Pushed " << val << ".\n";
                    break;
                case 2:
                    removeDuplicates(s);
                    break;
                case 3:
                    s.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q10 – Intersection of two stacks
        else if (choice == 10) {
            Stack s1, s2;
            int sub, val;
            Stack* result = NULL;

            do {
                cout << "\n-- Q10: Intersection --\n";
                cout << "1. Push to Stack 1\n";
                cout << "2. Push to Stack 2\n";
                cout << "3. Display Stack 1\n";
                cout << "4. Display Stack 2\n";
                cout << "5. Find Intersection\n";
                cout << "6. Display Intersection\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    s1.push(val);
                    cout << "Pushed " << val << " to Stack 1.\n";
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    s2.push(val);
                    cout << "Pushed " << val << " to Stack 2.\n";
                    break;
                case 3:
                    s1.display();
                    break;
                case 4:
                    s2.display();
                    break;
                case 5:
                    if (result != NULL) delete result;
                    result = intersection(s1, s2);
                    break;
                case 6:
                    if (result == NULL)
                        cout << "Intersection not computed yet!\n";
                    else
                        result->display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);

            if (result != NULL) delete result;
        }

        // Q11 – Subset check
        else if (choice == 11) {
            Stack s1, s2;
            int sub, val;

            do {
                cout << "\n-- Q11: Subset Check --\n";
                cout << "1. Push to Stack 1 (potential subset)\n";
                cout << "2. Push to Stack 2 (superset)\n";
                cout << "3. Display Stack 1\n";
                cout << "4. Display Stack 2\n";
                cout << "5. Check if Stack 1 is subset of Stack 2\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    s1.push(val);
                    cout << "Pushed " << val << " to Stack 1.\n";
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    s2.push(val);
                    cout << "Pushed " << val << " to Stack 2.\n";
                    break;
                case 3:
                    s1.display();
                    break;
                case 4:
                    s2.display();
                    break;
                case 5:
                    if (isSubset(s1, s2))
                        cout << "Stack 1 IS a subset of Stack 2.\n";
                    else
                        cout << "Stack 1 is NOT a subset of Stack 2.\n";
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q12 – Swap top two elements
        else if (choice == 12) {
            Stack s;
            int sub, val;
            do {
                cout << "\n-- Q12: Swap Top Two --\n";
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Swap Top Two\n";
                cout << "4. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    s.push(val);
                    cout << "Pushed " << val << ".\n";
                    break;
                case 2:
                    val = s.pop();
                    if (val != -1) cout << "Popped " << val << ".\n";
                    break;
                case 3:
                    swapTop(s);
                    break;
                case 4:
                    s.display();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (sub != 0);
        }

        // Q13 – Stack of pointers
        else if (choice == 13) {
            PtrStack ps;
            int sub, val;
            do {
                cout << "\n-- Q13: Stack of Pointers --\n";
                cout << "1. Allocate int and push its address\n";
                cout << "2. Pop and free the pointer\n";
                cout << "3. Display\n";
                cout << "0. Back\n";
                cout << "Enter: ";
                cin >> sub;

                switch (sub) {
                case 1:
                    cout << "Enter value to allocate: ";
                    cin >> val;
                    {
                        int* p = new int(val);   // allocate on heap
                        ps.push(p);
                    }
                    break;
                case 2:
                    {
                        int* p = ps.pop();
                        if (p != NULL) {
                            cout << "Popped pointer (value = " << *p << "). Freeing memory.\n";
                            delete p;   // free the actual allocated int
                        }
                    }
                    break;
                case 3:
                    ps.display();
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
