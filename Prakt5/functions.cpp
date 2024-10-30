#include <iostream>
#include "functions.h"

using namespace std;

void menu() {
    PNode list = nullptr, tail = nullptr;
    int choice, value, beforeValue, afterValue;

    do {
        cout << "Menu:\n";
        cout << "1. Create list\n";
        cout << "2. Print list forward\n";
        cout << "3. Print list backward\n";
        cout << "4. Delete element\n";
        cout << "5. Insert element before another\n";
        cout << "6. Insert element after another\n";
        cout << "7. Check if list is symmetric\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list = createList(&tail);
                break;
            case 2:
                printForward(list);
                break;
            case 3:
                printBackward(tail);
                break;
            case 4:
                cout << "Enter value to delete: ";
                 cin >> value;
                deleteNode(&list, &tail, value);
                break;
            case 5:
                 cout << "Enter value before which to insert: ";
                 cin >> beforeValue;
                 cout << "Enter new value: ";
                 cin >> value;
                insertBefore(&list, beforeValue, value);
                break;
            case 6:
                 cout << "Enter value after which to insert: ";
                 cin >> afterValue;
                 cout << "Enter new value: ";
                 cin >> value;
                insertAfter(&list, &tail, afterValue, value);
                break;
            case 7:
                if (isSymmetric(list, tail)) {
                     cout << "List is symmetric.\n";
                } else {
                     cout << "List is not symmetric.\n";
                }
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Wrong input" << endl;
        }
    } while (choice != 0);
    freeMemory(&list);
}

void freeMemory(PNode *node) {
    while (*node != nullptr) {
        PNode temp = *node;
        *node = (*node)->next;
        delete temp;
    }
}

bool isSymmetric(PNode head, PNode tail) {
    if (!head) return true;

    while (head && tail && head != tail && head->prev != tail) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }

    return true;
}

void insertBefore(PNode *head, int beforeValue, int newValue) {
    PNode current = *head;

    while (current && current->data != beforeValue) {
        current = current->next;
    }

    if (!current) return;

    PNode newNode = new Node{newValue, current, current->prev};
    if (current->prev) current->prev->next = newNode;
    current->prev = newNode;

    if (current == *head) *head = newNode;
}

void insertAfter(PNode *head, PNode *tail, int afterValue, int newValue) {
    PNode currentHead = *head;

    if (afterValue == (*tail)->data) {
        PNode newNode = new Node{};
        newNode->data = newValue;
        newNode->next = nullptr;
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;

        return;
    }

    while (currentHead && currentHead->data != afterValue) {
        currentHead = currentHead->next;
    }

    if (!currentHead) return;

    Node *newNode = new Node{newValue, currentHead->next, currentHead};
    if (currentHead->next) currentHead->next->prev = newNode;
    currentHead->next = newNode;
}

void deleteNode(PNode *head, PNode *tail, int value) {
    PNode current = *head;

    if (value == (*tail)->data) {
        PNode toDelete = *tail;
        (*tail) = (*tail)->prev;
        (*tail)->next = nullptr;
        delete toDelete;
        return;
    }

    while (current && current->data != value) {
        current = current->next;
    }

    if (!current) return;

    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;

    if (current == *head) *head = current->next;

    delete current;
}

void printForward(PNode head) {
    Node *current = head;
    while (current) {
         cout << current->data << " ";
        current = current->next;
    }
     cout <<  endl;
}

void printBackward(PNode tail) {
    Node *current = tail;
    while (current) {
         cout << current->data << " ";
        current = current->prev;
    }
     cout <<  endl;
}

PNode createList(PNode *tail) {
    PNode head = nullptr;
    *tail = nullptr;
    int value;
    char choice;

    do {
         cout << "Enter value: ";
         cin >> value;

        Node *newNode = new Node{value, nullptr, nullptr};

        if (!head) {
            head = newNode;
            *tail = newNode;
        } else {
            (*tail)->next = newNode;
            newNode->prev = *tail;
            *tail = newNode;
        }

         cout << "Do you want to add another element? (y/n): ";
         cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return head;
}
