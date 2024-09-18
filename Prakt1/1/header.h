//
// Created by malinka on 18.09.24.
//

#ifndef HEADER_H
#define HEADER_H

// Визначення структури вузла однозв'язного списку
struct tnode {
    int info; // Поле для зберігання значення
    tnode *next; // Вказівник на наступний елемент списку
};

typedef tnode *pnode; // Вказівник на tnode

// Функція для створення LIFO-списку, яка повертає голову.
pnode formLIFO_1();

// Функція для створення LIFO-списку, яка нічого не повертає, а голову формує за допомогою параметра
void formLIFO_2(pnode *top);

// Функція для виведення елементів списку
void display(const pnode node);

#endif //HEADER_H
