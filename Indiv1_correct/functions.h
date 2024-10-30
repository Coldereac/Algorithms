//
// Created by malinka on 30.10.24.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define STARTFILECOUNTRIES "/home/malinka/CLionProjects/Algorithms/cmake-build-debug/Indiv1_correct/textFiles/countries.txt"
#define STARTFILETEAMS "/home/malinka/CLionProjects/Algorithms/cmake-build-debug/Indiv1_correct/textFiles/teams.txt"

#include "handlers/handlers.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct Team {
    string name; //Назва(Унікальна)
    int rank; //Місце
    int points; //Кількість очок у теперешньому раунді
    Team *next; // Посилання на наступну команду

    explicit Team(const string &n = "", int r = 0) : name(n), rank(r), points(0), next(nullptr) {
    }
};

struct Country {
    string name; //Назва(Унікальна)
    Team *teamList; //Список команд
    Country *next; //Наступна країна

    explicit Country(const string &n = "") : name(n), teamList(nullptr), next(nullptr) {
    }
};

Country *loadCountriesFromFile(const string &countriesFile);

Team *loadTeamsRanksFromFile(const string &teamsFile);

void saveTeamsRanksToFile(const string &teamsFile, Team *teamList);

void saveCountriesToFile(const string &countriesFile, Country *countryList);

void simulateRound(Team **teamList);

void refreshPlacements(Team **teamList);

void transferToNewRound(Team **teamList);

void removeTeamInCountry(Country **country, string &teamName);

int removeCountry(Country **countryList, string &countryName);

void addCountry(Country **countryList, Country *newCountry);

void addTeamInCountry(Country **country, Team **teamList, Team *newTeam);

Team *findTeamByName(Country *countryList, string &teamName);

Team *findTeamByRank(Country *countryList, int rank);

Team *findTeamByPoints(Country *countryList, int min, int max);

Country *findCountryByName(Country *countryList, string &countryName);

Country *findCountryByTeam(Country *countryList, string &teamName);

void syncTeams(Team *teamList, Country **countryList);

void deleteCountriesWithoutTeams(Country **countryList);

void sortTeamList(Team **teamList);

void displayTeam(Team *team);

void displayTeamList(Team *teamList);

void displayCountry(Country *country);

void displayCountryList(Country *countryList);

int findRank(Team *teamList, const string &teamName);

void justifyRanksAndPoints(Country **countryList, Team *teamList);

#endif //FUNCTIONS_H
