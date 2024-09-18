#ifndef ALGORITHMS_FUNCTIONS_H
#define ALGORITHMS_FUNCTIONS_H

#include <iostream>

#define FILEPATH "../Prakt1/3/footballers.bin" // Шлях до файлу для збереження даних про футболістів

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

// Виведення інформації про одного футболіста
void printFootballer(Footballer *footballer);

// Запис списку футболістів у файл
void writeToFile(PNode &head, const char *filename);

// Читання списку футболістів з файлу
void readFromFile(PNode &head, const char *filename);

// Додавання нового футболіста у список
void addFootballer(PNode &head, Footballer newFootballer);

// Пошук найкращого нападника (за кількістю голів)
void findBestForwarder(PNode head, Footballer *bestForwarder);

// Виведення всієї команди (всіх футболістів у списку)
void printTeam(PNode head);

// Пошук футболістів, які зіграли менше ніж 5 матчів
void findLess5Games(PNode head, PNode &result);

// Виведення амплуа (позиції) футболіста
void outputAmplua(AmplayType amplayType);

// Видалення футболіста зі списку
void deleteFootballer(PNode &head, Footballer toDelete);

// Виведення меню вибору дій для користувача
void printMenu();

// Меню для додавання футболіста
void addFootballerMenu(PNode &head);

// Меню для видалення футболіста
void deleteFootballerMenu(PNode &head);

// Меню для пошуку найкращого нападника
void findBestForwardMenu(PNode head);

// Меню для пошуку футболістів з менше ніж 5 зіграними матчами
void findLess5GamesMenu(PNode head);

#endif // ALGORITHMS_FUNCTIONS_H
