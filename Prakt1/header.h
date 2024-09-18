

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
void formLIFO_2(pnode *head);

// Функція для виведення елементів списку
void display(pnode node);

// Функція для створення FIFO-списку, яка повертає голову.
pnode formFIFO();

#endif //HEADER_H
