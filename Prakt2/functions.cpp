#include <iostream>
#include "header.h"
using namespace std;


pnode formLIFO_1() {
    int info;
    pnode head = NULL, cur;
    printf("Enter numbers in list(end with 0): ");
    cin >> info; // Введення значення
    while (info) {
        // Поки введене значення не 0
        cur = new tnode; // Створення нового елемента списку
        cur->info = info; // Присвоєння значення
        cur->next = head; // Наступний елемент вказує на попередній
        head = cur; // Оновлення вершини списку
        cin >> info; // Введення наступного значення
    }
    return head; // Повернення вершини списку
}


void formLIFO_2(pnode *head) {
    int info;
    pnode cur;
    *head = NULL; // Ініціалізація вершини
    printf("Enter numbers in list(end with 0): ");
    cin >> info;
    while (info) {
        cur = new tnode; // Створення нового елемента
        cur->info = info;
        cur->next = *head; // Вказівник на попередню вершину
        *head = cur; // Оновлення вершини
        cin >> info;
    }
}


void display(pnode node) {
    pnode cur = node;
    while (cur != NULL) {
        // Поки не кінець списку
        printf("%d ", cur->info); // Виведення значення
        cur = cur->next; // Перехід до наступного елемента
    }
    printf("\n"); // Перехід на новий рядок після виведення списку
}

pnode formFIFO() {
    pnode tail = NULL, head = NULL; // Ініціалізуємо вказівники на голову і хвіст списку
    int info;
    printf("Enter numbers in list(end with 0): ");
    while (cin >> info && info) { // Читаємо значення, поки не введено 0
        pnode cur = new tnode; // Створюємо новий елемент списку
        cur->info = info; // Записуємо введене значення
        cur->next = NULL; // Наступного елемента поки немає
        if (head == NULL) { // Якщо це перший елемент, він стає і головою, і хвостом списку
            head = cur;
            tail = cur;
        } else { // Якщо список вже існує, додаємо новий елемент в кінець
            tail->next = cur; // Останній елемент вказує на новий
            tail = cur; // Оновлюємо хвіст списку
        }
    }
    return head; // Повертаємо голову списку
}
