#include <iostream>
#include "header.h"
using namespace std;


pnode formLIFO_1() {
    int info;
    pnode top = NULL, cur;
    cin >> info; // Введення значення
    while (info) { // Поки введене значення не 0
        cur = new tnode; // Створення нового елемента списку
        cur->info = info; // Присвоєння значення
        cur->next = top; // Наступний елемент вказує на попередній
        top = cur; // Оновлення вершини списку
        cin >> info; // Введення наступного значення
    }
    return top; // Повернення вершини списку
}

// Функція для створення LIFO-списку з передаванням вказівника на вершину
void formLIFO_2(pnode *top) {
    int info;
    pnode cur;
    *top = NULL; // Ініціалізація вершини
    cin >> info;
    while (info) {
        cur = new tnode; // Створення нового елемента
        cur->info = info;
        cur->next = *top; // Вказівник на попередню вершину
        *top = cur; // Оновлення вершини
        cin >> info;
    }
}

// Функція для виведення елементів списку
void display(pnode node) {
    pnode cur = node;
    while (cur != NULL) { // Поки не кінець списку
        printf("%d ", cur->info); // Виведення значення
        cur = cur->next; // Перехід до наступного елемента
    }
    printf("\n"); // Перехід на новий рядок після виведення списку
}
