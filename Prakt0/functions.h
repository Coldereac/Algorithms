//
// Created by Malinka on 9/11/2024.
//

#ifndef ALGORITHMS_FUNCTIONS_H
#define ALGORITHMS_FUNCTIONS_H

#include <cstring>
#include <iostream>
#include <string>

#define FILEPATH "../Prakt0/footballers.bin"

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


struct Team {
    Footballer *players;
    int size;
};

void printFootballer(Footballer *footballer);

void writeToFile(const Team *team, const char *filename);

void readFromFile(Team *team, const char *filename);

void addFootballer(Team *team, Footballer newFootballer);

void findBestForwarder(Team *team, Footballer *bestForwarder);

void printTeam(Team *team);

void findLess5Games(Team *team, Team *result);

void outputAmplua(AmplayType amplayType);

void deleteFootballer(Team *team, Footballer toDelete);

#endif //ALGORITHMS_FUNCTIONS_H
