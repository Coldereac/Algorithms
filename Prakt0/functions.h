//
// Created by Malinka on 9/11/2024.
//

#ifndef ALGORITHMS_FUNCTIONS_H
#define ALGORITHMS_FUNCTIONS_H

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef enum {
    GOALKEEPER, DEFENDER, MIDFIELDER, FORWARD
} AmplayType;

struct Footballer {
    char lastName[50];
    AmplayType amplay;
    int age;
    int numberOfGames;
    int numberOfGoals;
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

void findLessThan5Games(Team *team, Team *result);

void outputAmplua(AmplayType amplayType);

#endif //ALGORITHMS_FUNCTIONS_H
