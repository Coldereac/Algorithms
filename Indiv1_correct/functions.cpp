//
// Created by malinka on 30.10.24.
//

#include "functions.h"


Country *loadCountriesFromFile(const string &countriesFile) {
    ifstream inFile(countriesFile);
    if (!inFile) {
        throw invalid_argument("Countries file can not be opened");
    }
    Country *countryList = nullptr;
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string countryName;
        ss >> countryName;
        auto newCountry = new Country(countryName);
        string teamName;
        Team *tempTeam = nullptr;
        while (ss >> teamName) {
            Team *newTeam = new Team(teamName);
            if (newCountry->teamList == nullptr) {
                newCountry->teamList = newTeam;
            } else {
                tempTeam->next = newTeam;
            }
            tempTeam = newTeam;
        }
        // Вставка страны в список по алфавиту
        if (!countryList || countryList->name > countryName) {
            newCountry->next = countryList;
            countryList = newCountry;
        } else {
            Country *current = countryList;
            while (current->next && current->next->name < countryName) {
                current = current->next;
            }
            newCountry->next = current->next;
            current->next = newCountry;
        }
    }
    inFile.close();

    return countryList;
}

Team *loadTeamsRanksFromFile(const string &teamsFile) {
    ifstream inFileRanks(teamsFile);
    if (!inFileRanks) {
        throw invalid_argument("Teams file cannot be opened");
    }

    Team *teamList = nullptr;
    Team *temp = nullptr;
    int rank = 1;
    string line;
    while (getline(inFileRanks, line)) {
        Team *newTeam = new Team(line, rank++);
        if (teamList == nullptr) {
            teamList = newTeam;
        } else {
            temp->next = newTeam;
        }
        temp = newTeam;
    }
    inFileRanks.close();
    return teamList;
}

void saveTeamsRanksToFile(const string &teamsFile, Team *teamList) {
    ofstream outFileRanks(teamsFile);
    if (!outFileRanks) {
        throw invalid_argument("Teams file cannot be opened");
    }
    Team *currentTeam = teamList;
    while (currentTeam) {
        outFileRanks << currentTeam->name << endl;
        currentTeam = currentTeam->next;
    }
    outFileRanks.close();
}

void saveCountriesToFile(const string &countriesFile, Country *countryList) {
    ofstream outFileCountries(countriesFile);
    if (!outFileCountries) {
        throw invalid_argument("Countries file cannot be opened");
    }
    Country *temp = countryList;
    while (temp) {
        outFileCountries << temp->name << " ";
        Team *tempTeam = temp->teamList;
        while (tempTeam) {
            outFileCountries << tempTeam->name << " ";
            tempTeam = tempTeam->next;
        }
        outFileCountries << endl;
        temp = temp->next;
    }
}

void displayTeam(const Team *team) {
    if (team == nullptr) {
        return;
    }
    cout << "Team Name: " << team->name << " Rank: " << team->rank
            << " Points: " << team->points << endl;
}

void displayTeamList(Team *teamList) {
    Team *temp = teamList;
    while (temp) {
        try {
            displayTeam(temp);
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
        }
        temp = temp->next;
    }
}

void displayCountry(const Country *country) {
    if (country == nullptr) {
        return;
    }
    cout << "Country Name: " << country->name << " Teams: " << endl;
    try {
        displayTeamList(country->teamList);
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }
}

void displayCountryList(const Country *countryList) {
    while (countryList) {
        try {
            displayCountry(countryList);
        } catch (invalid_argument &e) {
            cout << e.what() << endl;
        }
        countryList = countryList->next;
    }
}

int findRank(Team *teamList, const string &teamName) {
    Team *temp = teamList;
    while (temp) {
        if (temp->name == teamName) {
            return temp->rank;
        }
        temp = temp->next;
    }
    return -1;
}

int findPoints(Team *teamList, const string &teamName) {
    Team *temp = teamList;
    while (temp) {
        if (temp->name == teamName) {
            return temp->points;
        }
        temp = temp->next;
    }
    return -1;
}

void transferRanksAndPoints(Country **countryList, Team *teamList) {
    Country *tempCountry = *countryList;
    while (tempCountry) {
        Team *tempTeam = tempCountry->teamList;
        while (tempTeam) {
            tempTeam->rank = findRank(teamList, tempTeam->name);
            tempTeam->points = findPoints(teamList, tempTeam->name);
            tempTeam = tempTeam->next;
        }
        sortTeamList(&tempCountry->teamList);
        tempCountry = tempCountry->next;
    }
}

void simulateRound(Team **teamList) {
    Team *temp = *teamList;
    while (temp) {
        temp->points = 1 + rand() % 101;
        temp = temp->next;
    }
}

void sortTeamList(Team **teamList) {
    if (!teamList || !(*teamList) || !(*teamList)->next) return;

    Team *sorted = nullptr;

    while (*teamList) {
        Team *current = *teamList;
        *teamList = (*teamList)->next;


        if (!sorted || current->points > sorted->points) {
            current->next = sorted;
            sorted = current;
        } else {
            Team *temp = sorted;
            while (temp->next && temp->next->points > current->points) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    *teamList = sorted;
}

void refreshPlacements(Team **teamList) {
    sortTeamList(teamList);
    Team *current = *teamList;
    int currentRank = 1;

    while (current != nullptr) {
        Team *startGroup = current;
        int points = current->points;


        while (current->next != nullptr && current->next->points == points) {
            current = current->next;
        }


        if (startGroup != current) {
            Team *temp = startGroup;
            while (temp != current->next) {
                temp->rank = rand() % 100 + 1;
                temp = temp->next;
            }

            for (Team *i = startGroup; i != current->next; i = i->next) {
                for (Team *j = i->next; j != current->next; j = j->next) {
                    if (i->rank < j->rank) {
                        swap(i->rank, j->rank);
                        swap(i->name, j->name);
                        swap(i->points, j->points);
                    }
                }
            }
        } else {
            startGroup->rank = currentRank;
        }

        Team *temp = startGroup;
        while (temp != current->next) {
            temp->rank = currentRank++;
            temp = temp->next;
        }

        current = current->next;
    }
}

Team *findTeamByName(Team *teamList, const string &teamName) {
    Team *temp = teamList;
    while (temp) {
        if (temp->name == teamName) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void removeTeamInCountry(Country **country, const string &teamName) {
    Country *tempCountry = *country;
    Team *current = tempCountry->teamList;
    if (current->name == teamName) {
        tempCountry->teamList = current->next;
        delete current;
        return;
    }

    while (current->next && current->next->name != teamName) {
        current = current->next;
    }

    if (current->next) {
        Team *temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

void removeTeamFromTeamList(Team **teamList, const string &teamName) {
    Team *current = *teamList;
    if (current->name == teamName) {
        *teamList = current->next;
        delete current;
        return;
    }

    while (current->next && current->next->name != teamName) {
        current = current->next;
    }

    if (current->next) {
        Team *temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}


void syncTeams(Team *teamList, Country **countryList) {
    Country *tempCountry = *countryList;
    while (tempCountry) {
        Team *tempTeam = tempCountry->teamList;
        while (tempTeam) {
            if (findTeamByName(teamList, tempTeam->name) == nullptr) {
                removeTeamInCountry(&tempCountry, tempTeam->name);
            }
            tempTeam = tempTeam->next;
        }
        tempCountry = tempCountry->next;
    }
}

void freeMemoryTeamList(Team **teamList) {
    Team *current = *teamList;
    Team *next = nullptr;

    while (current) {
        next = current->next;
        delete current;
        current = next;
    }

    *teamList = nullptr;
}

void transferToNewRound(Team **teamList) {
    Team *tempTeam = *teamList;
    int size = 0;
    while (tempTeam) {
        size++;
        tempTeam->points = 0;
        tempTeam = tempTeam->next;
    }
    tempTeam = *teamList;
    for (int i = 0; i < size / 2 - 1; i++) {
        tempTeam = tempTeam->next;
    }
    freeMemoryTeamList(&tempTeam->next);
    tempTeam->next = nullptr;
}

void deleteCountriesWithoutTeams(Country **countryList) {
    Country *current = *countryList;
    Country *prev = nullptr;

    while (current) {
        if (current->teamList == nullptr) {
            if (prev == nullptr) {
                *countryList = current->next;
            } else {
                prev->next = current->next;
            }
            Country *toDelete = current;
            current = current->next;
            delete toDelete;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void deleteCountry(Country **countryList, const string &countryName) {
    if (!*countryList) throw invalid_argument("Country list is null");
    if ((*countryList)->name == countryName) {
        Country *temp = *countryList;
        *countryList = (*countryList)->next;
        freeMemoryTeamList(&temp->teamList);
        delete temp;
    }

    Country *current = *countryList;
    while (current->next && current->next->name != countryName) {
        current = current->next;
    }

    if (current->next) {
        Country *temp = current->next;
        current->next = temp->next;
        freeMemoryTeamList(&temp->teamList);
        delete temp;
    }
}

void addTeamInCountry(Country **country, Team **teamList, Team *newTeam) {
    if (!*country) throw invalid_argument("Country is null");
    if (!*teamList) throw invalid_argument("Team list is null");

    if ((*teamList)->points > 0) {
        // Присвоение очков для новой команды
        newTeam->points = rand() % 100 + 1;

        // Вставка команды в country->teamList с сортировкой по очкам
        Team **tempTeamList = &((*country)->teamList);
        while (*tempTeamList && (*tempTeamList)->points >= newTeam->points) {
            tempTeamList = &((*tempTeamList)->next);
        }
        newTeam->next = *tempTeamList;
        *tempTeamList = newTeam;

        // Вставка команды в teamList с сортировкой по очкам
        Team **tempTeamListMain = teamList;
        while (*tempTeamListMain && (*tempTeamListMain)->points >= newTeam->points) {
            tempTeamListMain = &((*tempTeamListMain)->next);
        }
        newTeam->next = *tempTeamListMain;
        *tempTeamListMain = newTeam;

        // Обновляем ранги
        refreshPlacements(teamList);
    } else {
        if ((*country)->teamList == nullptr) {
            (*country)->teamList = newTeam;
            (*country)->teamList->next = nullptr;
        } else {
            // Вставка в конец списка country->teamList
            Team *tempTeam = (*country)->teamList;

            while (tempTeam->next) {
                tempTeam = tempTeam->next;
            }
            tempTeam->next = newTeam;
        }

        // Вставка в конец списка teamList
        int rank = 1; // начинаем ранжировать с 1
        if (*teamList == nullptr) {
            *teamList = newTeam;
            (*teamList)->next = nullptr;
        } else {
            Team *temp = *teamList;

            while (temp->next) {
                temp = temp->next;
                rank++;
            }
            newTeam->rank = rank + 1;
            temp->next = newTeam;
        }
    }
}


void addCountry(Country **countryList, Country *newCountry) {
    if (!countryList || (*countryList)->name > newCountry->name) {
        newCountry->next = *countryList;
        *countryList = newCountry;
    } else {
        Country *current = *countryList;
        while (current->next && current->next->name < newCountry->name) {
            current = current->next;
        }
        newCountry->next = current->next;
        current->next = newCountry;
    }
}

Team *findTeamByRank(Team *teamList, int rank) {
    if (!teamList) throw invalid_argument("Team list is null");
    Team *current = teamList;
    while (current) {
        if (current->rank == rank) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

Team *findTeamByPoints(Team *teamList, int min, int max) {
    if (!teamList) throw invalid_argument("Team list is null");
    Team *current = teamList;
    Team *result = nullptr;
    Team *resultTail = nullptr;

    while (current) {
        if (current->points >= min && current->points <= max) {
            Team *newTeam = new Team(current->name, current->rank);
            newTeam->points = current->points;
            newTeam->next = nullptr;

            if (!result) {
                result = newTeam;
                resultTail = result;
            } else {
                resultTail->next = newTeam;
                resultTail = resultTail->next;
            }
        }
        current = current->next;
    }
    return result;
}

Country *findCountryByName(Country *countryList, const string &countryName) {
    if (!countryList) throw invalid_argument("Country list is nullptr");
    Country *current = countryList;
    while (current) {
        if (current->name == countryName) return current;
        current = current->next;
    }
    return nullptr;
}

Country *findCountryByTeam(Country *countryList, const string &teamName) {
    if (!countryList) throw invalid_argument("Country list is nullptr");
    Country *current = countryList;
    while (current) {
        Team *currentTeam = current->teamList;
        while (currentTeam) {
            if (currentTeam->name == teamName) return current;
            currentTeam = currentTeam->next;
        }
        current = current->next;
    }
    return nullptr;
}
