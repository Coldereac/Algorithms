#include "functions.h"
#include <iostream>
using namespace std;

// Функція для вставлення елемента у впорядкований список
void insertOrdered(PNode *head, int value) {
    PNode newNode = new Node{value, nullptr};

    // Якщо список порожній або новий елемент менший за перший, вставляємо на початок
    if (!*head || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Шукаємо позицію для вставки
        PNode current = *head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void createOrderedList(PNode *head, int size) {
    for (int i = 0; i < size; i++) {
        int number;
        cout << "Input number: ";
        cin >> number;
        insertOrdered(head, number);
    }
}

// Функція для видалення елемента з упорядкованого списку
void deleteNode(PNode *head, int value) {
    if (!head) return; // Якщо список порожній

    // Якщо голова списку містить значення, яке потрібно видалити
    if ((*head)->data == value) {
        PNode temp = *head;
        *head = (*head)->next;
        delete temp;
    } else {
        // Шукаємо вузол, який треба видалити
        PNode current = *head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        // Якщо знайшли вузол, видаляємо його
        if (current->next) {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
}

// Функція для виведення елементів списку
void printList(Node *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
