#ifndef RECURSION_H
#define RECURSION_H
#include "functions.h"

// Рекурсивне видалення всіх елементів списку
void freeMemoryRecursively(PNode *node);

// Рекурсивне додавання нового елемента в кінець списку
void addFootballerRecursively(PNode *head, Footballer &newFootballer);

// Рекурсивне виведення команди
void printTeamRecursively(PNode head);

// Рекурсивне знаходження найкращого форварда
void findBestForwardRecursively(PNode head, Footballer &bestForwarder);

// Рекурсивний пошук футболістів з менше ніж 5 матчами
void findLess5GamesRecursively(PNode head, PNode *result);

// Меню для вибору рекурсивних функцій
void recursionMenu(PNode *head);

bool insertBeforeRecursive(PNode *head, const Footballer &newFootballer, int targetIndex);

bool insertAfterRecursive(PNode *head, const Footballer &newFootballer, int targetIndex);

bool deleteFootballerRecursive(PNode *head, int targetIndex);

void findBestForwardMenuRecurs(PNode head);

void findLess5GamesMenuRecurs(PNode head);

void addFootballerMenuRecurs(PNode *head);

void insertBeforeMenuRecurs(PNode *head);

void insertAfterMenuRecurs(PNode *head);

void deleteFootballerMenuRecurs(PNode *head);

void findNeededByIndex(PNode*head, PNode&temp);

#endif //RECURSION_H
