//
// Created by Malinka on 10/3/2024.
//

#ifndef ALGORITHMS_FUNCTIONS_H
#define ALGORITHMS_FUNCTIONS_H

/*
*2. Напишіть функції для створення двоспрямованих списків за
даними, введеними з клавіатури, а також функції виведення
елементів списку в обох напрямках (для кожного напрямку
своя функція).
3. Напишіть функції для видалення заданого елемента
(delet2Node(...)) з двоспрямованого списку, додавання нового
елемента перед заданим (insert2Before(...)) та після заданого
(insert2After(...)).
4. Напишіть функцію, яка перевіряє, чи є симетричним
двоспрямований список.
5. Сформуйте файл–header для роботи з двоспрямованими
списками та забезпечте модульність програми.
6. Розробіть меню для застосування всіх функцій за бажанням
користувача.
 */

struct Node {
    int data;
    Node *next;
    Node *prev;
};

typedef Node *PNode;

PNode createList(PNode *tail);

void printForward(PNode head);

void printBackward(PNode tail);

void deleteNode(PNode *head, PNode *tail, int value);

void insertBefore(PNode *head, int beforeValue, int newValue);

void insertAfter(PNode *head, PNode * tail, int afterValue, int newValue);

bool isSymmetric(PNode head, PNode tail);

void menu();

void freeMemory(PNode *node);

#endif //ALGORITHMS_FUNCTIONS_H
