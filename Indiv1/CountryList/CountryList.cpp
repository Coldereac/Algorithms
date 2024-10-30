#include "CountryList.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

Team::Team(string n = "", int r = 0) : name(std::move(n)), rank(r), next(nullptr) {
}

Country::Country(const string &n) : name(n), teamList(nullptr), next(nullptr) {
}


Country::Country(string &n) : name(n), teamList(nullptr), next(nullptr) {
}

CountryList::CountryList() : head(nullptr) {
}

Country *CountryList::getHead() const {
    return head;
}


int CountryList::addTeamToCountry(Country *country, const string &teamName, int rank) {
    Team *newTeam = new Team(teamName, rank);

    if (!country->teamList || country->teamList->rank > rank) {
        newTeam->next = country->teamList;
        country->teamList = newTeam;
    } else {
        Team *current = country->teamList;
        while (current->next && current->next->rank < rank) {
            current = current->next;
        }
        newTeam->next = current->next;
        current->next = newTeam;
    }

    return 0; // Успішно
}

Country *CountryList::findCountry(const string &countryName) const {
    Country *current = head;
    while (current) {
        if (current->name == countryName) return current;
        current = current->next;
    }
    return nullptr;
}

Team *CountryList::findTeamByName(const string &teamName, const Country *country) const {
    if (!country) country = head;
    while (country) {
        Team *current = country->teamList;
        while (current) {
            if (current->name == teamName) return current;
            current = current->next;
        }
        country = country->next;
    }
    return nullptr;
}

Team *CountryList::findTeamByRank(const int rank, const Country *country) const {
    if (!country) country = head;
    while (country) {
        Team *current = country->teamList;
        while (current) {
            if (current->rank == rank) return current;
            current = current->next;
        }
        country = country->next;
    }
    return nullptr;
}

int CountryList::addCountry(const string &countryName) {
    if (findCountry(countryName)) {
        return 4; // Країна вже існує
    }

    Country *newCountry = new Country(countryName);
    if (!head || head->name > countryName) {
        newCountry->next = head;
        head = newCountry;
    } else {
        Country *current = head;
        while (current->next && current->next->name < countryName) {
            current = current->next;
        }
        newCountry->next = current->next;
        current->next = newCountry;
    }

    return 0; // Успішно
}

int CountryList::addTeam(const string &countryName, const string &teamName, int rank) const {
    Country *country = findCountry(countryName);
    if (!country) {
        return 1; // Країна не знайдена
    }

    Team *current = country->teamList;
    while (current) {
        if (current->name == teamName) {
            return 5; // Команда вже існує
        }
        current = current->next;
    }

    return addTeamToCountry(country, teamName, rank);
}

int CountryList::removeCountry(const string &countryName) {
    if (!head) return 1; // Країна не знайдена

    if (head->name == countryName) {
        Country *temp = head;
        head = head->next;
        delete temp;
        return 0; // Успішно
    }

    Country *current = head;
    while (current->next && current->next->name != countryName) {
        current = current->next;
    }

    if (current->next) {
        Country *temp = current->next;
        current->next = temp->next;
        delete temp;
        return 0; // Успішно
    }

    return 1; // Країна не знайдена
}

int CountryList::removeTeam(const string &countryName, const string &teamName) const {
    Country *country = findCountry(countryName);
    if (!country) return 1; // Країна не знайдена
    if (!country->teamList) return 2; // Команда не знайдена

    Team *current = country->teamList;
    if (current->name == teamName) {
        country->teamList = current->next;
        delete current;
        return 0; // Успішно
    }

    while (current->next && current->next->name != teamName) {
        current = current->next;
    }

    if (current->next) {
        Team *temp = current->next;
        current->next = temp->next;
        delete temp;
        return 0; // Успішно
    }

    return 2; // Команда не знайдена
}

// Редагування назви країни
int CountryList::editCountry(const string &oldName, const string &newName) {
    Country *country = findCountry(oldName);
    if (!country) return 1; // Країна не знайдена

    country->name = newName;
    return 0; // Успішно
}

// Редагування команди
int CountryList::editTeamName(const string &newTeamName, Team *team) {
    team->name = newTeamName;
    return 0; // Успішно
}

int CountryList::editTeamRank(const int newRank, Team *team) {
    team->rank = newRank;
    return 0;
}

// Виведення усіх країн та команд
void CountryList::displayCountries(Country *head) {
    Country *currentCountry = head;
    while (currentCountry) {
        displayCountry(currentCountry);
        currentCountry = currentCountry->next;
    }
}

void CountryList::displayCountry(Country *country) {
    cout << "Country: " << country->name << endl;
    Team *currentTeam = country->teamList;
    while (currentTeam) {
        displayTeam(currentTeam);
        currentTeam = currentTeam->next;
    }
}

void CountryList::displayTeam(Team *team) {
    cout << "Team: " << team->name << ", Rank: " << team->rank << endl;
}

int CountryList::getTeamRank(Team *teamList, const string &teamName) {
    Team *current = teamList;
    while (current) {
        if (current->name == teamName) {
            return current->rank;
        }
        current = current->next;
    }
    return -1; //Не знайдена така команда
}

int CountryList::loadFromFile(const string &countriesFile, const string &teamsFile) {
    ifstream inFile(countriesFile);
    if (!inFile) {
        return 3; // Помилка відкриття файлу
    }

    ifstream inFileRanks(teamsFile);
    if (!inFileRanks) {
        return 3; // Помилка відкриття файлу
    }

    int rank = 1;
    string line;
    Team *teamList = nullptr;
    Team *temp = nullptr;
    while (getline(inFileRanks, line)) {
        Team *newTeam = new Team;
        newTeam->name = line;
        newTeam->rank = rank;
        newTeam->next = nullptr;
        rank++;
        if (teamList == nullptr) {
            teamList = newTeam;
        } else {
            temp->next = newTeam;
        }
        temp = newTeam;
    }

    while (getline(inFile, line)) {
        stringstream ss(line);
        string countryName;
        ss >> countryName;
        addCountry(countryName);

        string teamName;
        while (ss >> teamName) {
            addTeam(countryName, teamName, getTeamRank(teamList, teamName));
        }
    }

    inFile.close();

    inFileRanks.close();

    return 0; // Успішно
}


void insertOrdered(Team **teamList, Team *insert) {
    Team *newNode = new Team();
    *newNode = *insert;
    newNode->next = NULL;

    if (!*teamList || (*teamList)->rank >= newNode->rank) {
        newNode->next = *teamList;
        *teamList = newNode;
    } else {
        Team *current = *teamList;
        // Пошук місця для вставки
        while (current->next && current->next->rank < newNode->rank) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


int CountryList::saveToFile(const string &countriesFile, const string &teamsFile) const {
    ofstream outFileCountries(countriesFile);
    if (!outFileCountries) {
        return 3; // Помилка відкриття файлу для запису
    }

    Country *currentCountry = head;
    while (currentCountry) {
        outFileCountries << currentCountry->name;
        Team *currentTeam = currentCountry->teamList;
        while (currentTeam) {
            outFileCountries << " " << currentTeam->name;
            currentTeam = currentTeam->next;
        }
        outFileCountries << endl;
        currentCountry = currentCountry->next;
    }
    outFileCountries.close();

    ofstream outFileTeams(teamsFile);
    if (!outFileTeams) {
        return 3; // Помилка відкриття файлу для запису
    }
    currentCountry = head;
    Team *teamList = nullptr;
    Team *currentTeam = nullptr;
    while (currentCountry) {
        currentTeam = currentCountry->teamList;
        while (currentTeam) {
            insertOrdered(&teamList, currentTeam);
            currentTeam = currentTeam->next;
        }
        currentCountry = currentCountry->next;
    }
    while (teamList) {
        outFileTeams << teamList->name << endl;
        teamList = teamList->next;
    }
    outFileTeams.close();

    return 0; // Успішно
}

void CountryList::recalculateRanks() const {
    Country *currentCountry = head;
    vector<Team *> teamList;
    while (currentCountry != nullptr) {
        Team *currentTeam = currentCountry->teamList;
        while (currentTeam != nullptr) {
            teamList.push_back(currentTeam);
            currentTeam = currentTeam->next;
        }

        currentCountry = currentCountry->next;
    }
    sort(teamList.begin(), teamList.end(), [](Team *a, Team *b) {
        return a->rank < b->rank;
    });

    int newRank = 1;
    for (auto &team: teamList) {
        team->rank = newRank;
        newRank++;
    }
}
