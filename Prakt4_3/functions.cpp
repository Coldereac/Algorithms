#include "functions.h"
#include <iostream>
using namespace std;

// Функція для вставлення елемента у впорядкований список
void insertOrdered(PNode *head, int value) {
    PNode newNode = new Node{value, nullptr};

    PNode current = (*head);
    while (current->next && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void createOrderedList(PNode *head, int size) {
    for (int i = 0; i < size; i++) {
        int number;
        cout << "Input number(1-99): ";
        cin >> number;
        if (number < 1 || number > 99) {
            cout << "Invalid input!" << endl;
            i--;
        } else {
            insertOrdered(head, number);
        }
    }
}

// Функція для видалення елемента з упорядкованого списку
void deleteNode(PNode *head, int value) {
    if (!(*head)) return; // Якщо список порожній

    PNode current = *head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    // Якщо знайшли вузол, видаляємо його
    if (current->next) {
        PNode temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Функція для виведення елементів списку
void printList(PNode head) {
    PNode temp = head->next;
    while (temp->next) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
