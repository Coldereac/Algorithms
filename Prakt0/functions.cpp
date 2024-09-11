//
// Created by Malinka on 9/11/2024.
//

#include "functions.h"

using namespace std;

// Функція для запису команди у бінарний файл
void writeToFile(const Team *team, const char *filename) {
    FILE *file;
    if ((file = fopen(filename, "wb")) == NULL) {
        perror("Error opening file");
        return;
    }
    fwrite(&team->size, sizeof(int), 1, file);

    fwrite(team->players, team->size * sizeof(Footballer), 1, file);
    fclose(file);
}

// Функція для читання команди з бінарного файлу
void readFromFile(Team *team, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        puts("New file will be created after first saving to file");
        return;
    }
    fread(&team->size, sizeof(int), 1, file);
    team->players = (Footballer *) malloc(team->size * sizeof(Footballer));
    fread(team->players, team->size * sizeof(Footballer), 1, file);
    fclose(file);
}

void addFootballer(Team *team, Footballer newFootballer) {
    if (team->players == NULL) {
        team->players = (Footballer *) malloc(sizeof(Footballer));
    } else {
        team->players = (Footballer *) realloc(team->players, (team->size + 1) * sizeof(Footballer));
    }
    team->players[team->size] = newFootballer;
    team->size++;
    writeToFile(team, "footballers.bin");
}

bool equals(const Footballer *a, const Footballer *b) {
    return strcmp(a->lastName, b->lastName) == 0 && a->amplay == b->amplay && a->age == b->age &&
           a->numberOfGoals == b->numberOfGoals && a->numberOfGames == b->numberOfGames;
}

void deleteFootballer(Team *team, Footballer toDelete) {
    int start = -1;
    int i = 0;
    while (i < team->size && start == -1) {
        if (equals(&team->players[i], &toDelete)) {
            start = i;
        }
        i++;
    }
    for (i = start; i < team->size - 1; ++i) {
        team->players[i] = team->players[i + 1];
    }
    team->players = (Footballer *) realloc(team->players, (team->size - 1) * sizeof(Footballer));
    team->size--;
}

void printFootballer(Footballer *footballer) {
    cout << "Name: " << footballer->lastName <<
         " Amplua: ";
    outputAmplua(footballer->amplay);
    cout << " Age: " << footballer->age <<
         " Number of games: " << footballer->numberOfGames <<
         " Number of goals: " << footballer->numberOfGoals << endl;
}

void printTeam(Team *team) {
    for (int i = 0; i < team->size; ++i) {
        printFootballer(&team->players[i]);
        cout << endl;
    }
}

void findLessThan5Games(Team *team, Team *result) {
    for (int i = 0; i < team->size; ++i) {
        if (team->players[i].numberOfGames < 5) {
            addFootballer(result, team->players[i]);
        }
    }
}

void findBestForwarder(Team *team, Footballer *bestForwarder) {
    for (int i = 0; i < team->size; ++i) {
        if (team->players[i].amplay == FORWARD && bestForwarder->numberOfGoals < team->players[i].numberOfGoals) {
            *bestForwarder = team->players[i];
        }
    }
}

void outputAmplua(AmplayType amplayType) {
    switch (amplayType) {
        case 0:
            cout << "Goalkeeper";
            break;
        case 1:
            cout << "Defender";
            break;
        case 2:
            cout << "Midfielder";
            break;
        case 3:
            cout << "Forward";
    }
}

