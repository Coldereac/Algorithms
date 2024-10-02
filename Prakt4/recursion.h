#ifndef RECURSION_H
#define RECURSION_H
#include "functions.h"

// Рекурсивне видалення всіх елементів списку
void freeMemoryRecursively(PNode *node);

// Рекурсивне додавання нового елемента в кінець списку
void addFootballerRecursively(PNode *head, Footballer newFootballer);

// Рекурсивне виведення команди
void printTeamRecursively(PNode head, int index = 0);

// Рекурсивне знаходження найкращого форварда
void findBestForwardRecursively(PNode head, Footballer *bestForwarder);

// Рекурсивний пошук футболістів з менше ніж 5 матчами
void findLess5GamesRecursively(PNode head, PNode *result);

// Меню для вибору рекурсивних функцій
void recursionMenu(PNode *head);

bool insertBeforeRecursive(PNode *head, const Footballer &newFootballer, const Footballer &targetFootballer);

bool insertAfterRecursive(PNode *head, const Footballer &newFootballer, const Footballer &targetFootballer);

bool deleteFootballerRecursive(PNode *head, const Footballer &targetFootballer);

void findBestForwardMenuRecurs(PNode head);

void findLess5GamesMenuRecurs(PNode head);

void addFootballerMenuRecurs(PNode *head);

void insertBeforeMenuRecurs(PNode *head);

void insertAfterMenuRecurs(PNode *head);

void deleteFootballerMenuRecurs(PNode *head);

#endif //RECURSION_H
