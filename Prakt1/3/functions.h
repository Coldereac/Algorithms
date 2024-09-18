#ifndef ALGORITHMS_FUNCTIONS_H
#define ALGORITHMS_FUNCTIONS_H

#include <iostream>
#include <string>

#define FILEPATH "../Prakt1/3/footballers.bin"

using namespace std;

enum AmplayType {
    GOALKEEPER, DEFENDER, MIDFIELDER, FORWARD
};

struct Footballer {
    char lastName[50];
    AmplayType amplay;
    int age;
    int games;
    int goals;
};

// Структура для вузла списку
struct Node {
    Footballer footballer; // Дані про футболіста
    Node *next; // Вказівник на наступний вузол
};

typedef Node *PNode;

void printFootballer(Footballer *footballer);

void writeToFile(PNode head, const char *filename);

void readFromFile(PNode &head, const char *filename);

void addFootballer(PNode &head, Footballer newFootballer);

void findBestForwarder(PNode head, Footballer *bestForwarder);

void printTeam(PNode head);

void findLess5Games(PNode head, PNode &result);

void outputAmplua(AmplayType amplayType);

void deleteFootballer(PNode &head, Footballer toDelete);

void printMenu();

void addFootballerMenu(PNode &head);

void deleteFootballerMenu(PNode &head);

void findBestForwardMenu(PNode head);

void findLess5GamesMenu(PNode head);

#endif // ALGORITHMS_FUNCTIONS_H
