//
// Created by Malinka on 10/3/2024.
//
#include <iostream>
#include "functions.h"

using namespace std;

void menu() {
    PNode list = nullptr;
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
                list = createList();
                break;
            case 2:
                printForward(list);
                break;
            case 3:
                if (list) {
                    Node *tail = list;
                    while (tail->next) {
                        tail = tail->next;
                    }
                    printBackward(tail);
                }
                break;
            case 4:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                deleteNode(&list, value);
                break;
            case 5:
                std::cout << "Enter value before which to insert: ";
                std::cin >> beforeValue;
                std::cout << "Enter new value: ";
                std::cin >> value;
                insertBefore(&list, beforeValue, value);
                break;
            case 6:
                std::cout << "Enter value after which to insert: ";
                std::cin >> afterValue;
                std::cout << "Enter new value: ";
                std::cin >> value;
                insertAfter(list, afterValue, value);
                break;
            case 7:
                if (isSymmetric(list)) {
                    std::cout << "List is symmetric.\n";
                } else {
                    std::cout << "List is not symmetric.\n";
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

bool isSymmetric(PNode head) {
    if (!head) return true;

    Node *tail = head;
    while (tail->next) {
        tail = tail->next;
    }

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

void insertAfter(PNode head, int afterValue, int newValue) {
    Node *current = head;

    while (current && current->data != afterValue) {
        current = current->next;
    }

    if (!current) return;

    Node *newNode = new Node{newValue, current->next, current};
    if (current->next) current->next->prev = newNode;
    current->next = newNode;
}

void deleteNode(PNode *head, int value) {
    PNode current = *head;

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
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void printBackward(PNode tail) {
    Node *current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

PNode createList() {
    Node *head = nullptr;
    Node *tail = nullptr;
    int value;
    char choice;

    do {
        std::cout << "Enter value: ";
        std::cin >> value;

        Node *newNode = new Node{value, nullptr, nullptr};

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        std::cout << "Do you want to add another element? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return head;
}

