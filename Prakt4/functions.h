#ifndef ALGORITHMS_FUNCTIONS_H
#define ALGORITHMS_FUNCTIONS_H

#include <iostream>

#define FILEPATH "footballers.bin" // Шлях до файлу для збереження даних про футболістів

using namespace std;

enum AmplayType {
    GOALKEEPER,
    DEFENDER,
    MIDFIELDER,
    FORWARD
};

struct Footballer {
    char lastName[50];
    AmplayType amplay;
    int age;
    int games;
    int goals;
    int index; // Додано поле індексу
};

struct Node {
    Footballer footballer;
    Node *next;
};

typedef Node *PNode;

bool isEmpty(PNode head);

bool equals(const Footballer &a, const Footballer &b);

void printFootballer(Footballer *footballer);

void writeToFile(PNode head, const char *filename);

void readFromFile(PNode *head, const char *filename);

void addFootballer(PNode *head, Footballer newFootballer);

void findBestForwarder(PNode head, Footballer *bestForwarder);

void printTeam(PNode head);

void findLess5Games(PNode head, PNode *result);

void outputAmplua(AmplayType amplayType);

void deleteFootballer(PNode *head, int index); // Зміна на прийом індексу
void printMenu();

void addFootballerMenu(PNode *head);

void deleteFootballerMenu(PNode *head);

void findBestForwardMenu(PNode head);

void findLess5GamesMenu(PNode head);

void freeMemory(PNode *node);

void insertAfterMenu(PNode *head);

void insertAfter(PNode *head, Footballer newFootballer, int targetIndex);

void insertBeforeMenu(PNode *head);

void insertBefore(PNode *head, Footballer newFootballer, int targetIndex);

Footballer createFootballer();

void findFootballerMenu(PNode head);

PNode findFootballer(PNode head, Footballer targetFootballer);

void addManyFootballersMenu(PNode *head);

void addManyFootballers(PNode *head, int amount);

void findMenu(PNode head);

void addMenu(PNode *head);

void refreshIndexes(PNode head, int startIndex = 0);

#endif // ALGORITHMS_FUNCTIONS_H
