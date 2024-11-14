//
// Created by malinka on 07.11.24.
//

#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#define STANDARDFILE "/home/malinka/CLionProjects/Algorithms/cmake-build-debug/Indiv2/data.txt"

// Клас, що представляє поїзд
class Train {
public:
    int number; // Номер поїзда
    string destination; // Призначення поїзда
    int departureMinutes; // Хвилини відправлення
    int departureHours; // Години відправлення

    // Конструктор поїзда з перевіркою даних
    Train(int number = 1, const string &destination = "", int departureHours = 0, int departureMinutes = 0);

    // Метод для виведення інформації про поїзд
    void printInfo() const;
};

// Вузол для дерева AVL, який містить дані про поїзд
class AVLNode {
public:
    Train data; // Дані про поїзд
    AVLNode *left; // Лівий дочірній вузол
    AVLNode *right; // Правий дочірній вузол
    int height; // Висота вузла

    explicit AVLNode(Train &data); // Конструктор вузла

    // Повертає висоту вузла
    [[nodiscard]] int getHeight() const;

    // Повертає баланс вузла для перевірки рівноваги
    [[nodiscard]] int getBalance() const;

    // Правий оберт для балансування
    AVLNode *rotateRight();

    // Лівий оберт для балансування
    AVLNode *rotateLeft();

    // Пошук мінімального значення (найлівійший вузол)
    AVLNode *findMin();
};

// Клас для управління розкладом поїздів
class Schedule {
    AVLNode *root; // Корінь дерева AVL

    // Зберігає дані в файл рекурсивно
    static void saveToFile(const AVLNode *node, ofstream &file);

    // Створює збалансоване дерево з файлу
    static AVLNode *buildBalancedTreeFromFile(ifstream &file, int start, int end);

    // Підраховує кількість вузлів у дереві
    static int countNodes(AVLNode *node);

public:
    Schedule(); // Конструктор для ініціалізації порожнього розкладу

    // Вставка нового поїзда в дерево
    void insert(Train &data);

    // Видалення поїзда за номером
    void remove(int number);

    // Виводить усі поїзди у порядку зростання номерів
    void displayAll() const;

    // Допоміжна функція для виведення
    static void displayAllHelper(const AVLNode *node);

    // Виводить поїзд за номером
    void displayTrainByNumber(int number) const;

    // Зберігає дерево в файл
    void saveToFile(const string &filename) const;

    // Завантажує дані з файлу
    void loadFromFile(const string &filename);

    // Пошук поїздів за призначенням
    Schedule *searchByDestination(const string &destination) const;

    // Допоміжна функція для пошуку за призначенням
    static void searchByDestinationHelper(AVLNode *node, const string &destination, Schedule *result);

    // Пошук поїзда за номером
    static AVLNode *searchByNumber(int number, AVLNode *node);


    // Рекурсивне додавання вузла в дерево
    static AVLNode *insert(AVLNode *node, Train &data);

    // Рекурсивне видалення вузла з дерева
    static AVLNode *remove(AVLNode *node, int number);

    // Звільняє пам'ять, видаляючи дерево
    static void destroyTree(AVLNode *node);

    ~Schedule(); // Деструктор для очищення дерева
};


#endif //SCHEDULE_H
