#ifndef ALGORITHMS_FUNCTIONS_H
#define ALGORITHMS_FUNCTIONS_H

/*
*Створіть список структур Футболіст (структура, яка створена в 1
практичній).
Реалізуйте функції:
визначити кращого форварда і вивести інформацію про нього;
вивести відомості про футболістів, які зіграли не менше 5-ти
ігор.
 */

#include <iostream>

#define FILEPATH "footballers.bin" // Шлях до файлу для збереження даних про футболістів

using namespace std;

// Перелічення, яке визначає можливі позиції (амплуа) для футболіста
enum AmplayType {
    GOALKEEPER, // Воротар
    DEFENDER, // Захисник
    MIDFIELDER, // Півзахисник
    FORWARD // Нападник
};

// Структура для збереження даних про футболіста
struct Footballer {
    char lastName[50]; // Прізвище футболіста
    AmplayType amplay; // Амплуа футболіста
    int age; // Вік футболіста
    int games; // Кількість зіграних матчів
    int goals; // Кількість забитих голів
};

// Структура для вузла списку, який зберігає дані про футболіста
struct Node {
    Footballer footballer; // Дані про футболіста
    Node *next; // Вказівник на наступний вузол списку
};

typedef Node *PNode; // Тип для зручного використання вказівників на вузли списку

// Перевірка, чи є список порожнім
bool isEmpty(PNode head);

// Функція порівняння двох футболістів
bool equals(const Footballer &a, const Footballer &b);

// Виведення інформації про одного футболіста
void printFootballer(Footballer *footballer);

// Запис списку футболістів у файл
void writeToFile(PNode head, const char *filename);

// Читання списку футболістів з файлу
void readFromFile(PNode *head, const char *filename);

// Додавання нового футболіста у список
void addFootballer(PNode *head, Footballer newFootballer);

// Пошук найкращого нападника (за кількістю голів)
void findBestForwarder(PNode head, Footballer *bestForwarder);

// Виведення всієї команди (всіх футболістів у списку)
void printTeam(PNode head);

// Пошук футболістів, які зіграли менше ніж 5 матчів
void findLess5Games(PNode head, PNode *result);

// Виведення амплуа (позиції) футболіста
void outputAmplua(AmplayType amplayType);

// Видалення футболіста зі списку
void deleteFootballer(PNode *head, Footballer toDelete);

// Виведення меню вибору дій для користувача
void printMenu();

// Меню для додавання футболіста
void addFootballerMenu(PNode *head);

// Меню для видалення футболіста
void deleteFootballerMenu(PNode *head);

// Меню для пошуку найкращого нападника
void findBestForwardMenu(PNode head);

// Меню для пошуку футболістів з менше ніж 5 зіграними матчами
void findLess5GamesMenu(PNode head);

//Вивільнення пам'яті
void freeMemory(PNode *node);

// Меню для вставки нового елемента після заданого
void insertAfterMenu(PNode *head);

// Вставка нового елемента після заданого
void insertAfter(PNode *head, Footballer newFootballer, Footballer targetFootballer);

// Меню для вставки нового елемента перед заданим
void insertBeforeMenu(PNode *head);

// Вставка нового елемента після заданим
void insertBefore(PNode *head, Footballer newFootballer, Footballer targetFootballer);

//Збирання інформації про нового футболіста
Footballer createFootballer();

#endif // ALGORITHMS_FUNCTIONS_H
