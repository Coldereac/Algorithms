#include "handlers.h"

using namespace std;


void handleLoadData(CountryList *countryList) {
    if (countryList->loadFromFile(COUNTRIESFILE, TEAMSFILE) == 0) {
        cout << "Data loaded successfully.\n";
    } else {
        cout << "Error loading data.\n";
    }
}

void handleAddCountry(CountryList *countryList) {
    string countryName;
    cout << "Enter country name: ";
    cin >> countryName;
    if (countryList->addCountry(countryName) == 0) {
        cout << "Country added successfully.\n";
    } else {
        cout << "Error: Country already exists.\n";
    }
}

void handleAddTeam(const CountryList *countryList) {
    string countryName, teamName;
    int rank;
    cout << "Enter country name: ";
    cin >> countryName;
    cout << "Enter team name: ";
    cin >> teamName;
    cout << "Enter team rank: ";
    cin >> rank;
    if (countryList->addTeam(countryName, teamName, rank - 1) == 0) {
        cout << "Team added successfully.\n";
        countryList->recalculateRanks();
    } else {
        cout << "Error: Could not add team.\n";
    }
}

void handleRemoveCountry(CountryList *countryList) {
    string countryName;
    cout << "Enter country name to remove: ";
    cin >> countryName;
    if (countryList->removeCountry(countryName) == 0) {
        cout << "Country removed successfully.\n";
    } else {
        cout << "Error: Country not found.\n";
    }
}

void handleRemoveTeam(const CountryList *countryList) {
    string countryName, teamName;
    cout << "Enter country name: ";
    cin >> countryName;
    cout << "Enter team name to remove: ";
    cin >> teamName;
    if (countryList->removeTeam(countryName, teamName) == 0) {
        cout << "Team removed successfully.\n";
        countryList->recalculateRanks();
    } else {
        cout << "Error: Team not found.\n";
    }
}

void handleEditCountry(CountryList *countryList) {
    string oldName, newName;
    cout << "Enter the current country name: ";
    cin >> oldName;
    cout << "Enter the new country name: ";
    cin >> newName;
    if (countryList->editCountry(oldName, newName) == 0) {
        cout << "Country updated successfully.\n";
    } else {
        cout << "Error: Country not found.\n";
    }
}

void handleEditTeam(CountryList *countryList) {
    char choice;

    string oldTeamName, newTeamName;
    int newRank;
    cout << "Enter the current team name: ";
    cin >> oldTeamName;
    Team *team = countryList->findTeamByName(oldTeamName);
    cout << "Do you want to change name?[y/n]";
    cin >> choice;
    if (choice == 'y') {
        cout << "Enter the new team name: ";
        cin >> newTeamName;
        CountryList::editTeamName(newTeamName, team);
    }
    cout << "Dou you want to change rank?[y/n]";
    cin >> choice;
    if (choice == 'y') {
        cout << "Enter the new team rank: ";
        cin >> newRank;
        CountryList::editTeamRank(newRank, team);
    }
    cout << "Team edited successfully\n";
}


void handleSaveData(const CountryList *countryList) {
    if (countryList->saveToFile(COUNTRIESFILE, TEAMSFILE) == 0) {
        cout << "Data saved successfully.\n";
    } else {
        cout << "Error saving data.\n";
    }
}

void handleFindTeamByName(const CountryList *countryList) {
    string teamName;
    cout << "Enter the team name: ";
    cin >> teamName;
    Team *founded = nullptr;
    if ((founded = countryList->findTeamByName(teamName)) != nullptr) {
        CountryList::displayTeam(founded);
    } else {
        cout << "Couldn't find team\n";
    }
}

void handleFindTeamByRank(const CountryList *countryList) {
    int rank;
    cout << "Enter the team rank: ";
    cin >> rank;
    Team *founded = nullptr;
    if ((founded = countryList->findTeamByRank(rank)) != nullptr) {
        CountryList::displayTeam(founded);
    } else {
        cout << "Couldn't find team\n";
    }
}

void handleFindCountry(const CountryList *countryList) {
    string countryName;
    cout << "Enter the country name: ";
    cin >> countryName;
    Country *founded = nullptr;
    if ((founded = countryList->findCountry(countryName)) != nullptr) {
        CountryList::displayCountry(founded);
    } else {
        cout << "Couldn't find team\n";
    }
}


// Подменю для поиска
void searchMenu(CountryList *countryList) {
    int choice;
    do {
        cout << "\n--- SEARCH MENU ---\n";
        cout << "1. Find Team by name\n";
        cout << "2. Find Team by rank\n";
        cout << "3. Find Country\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: handleFindTeamByName(countryList);
                break;
            case 2: handleFindTeamByRank(countryList);
                break;
            case 3: handleFindCountry(countryList);
                break;
            case 4: return; // Вернуться в главное меню
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

// Подменю для добавления
void addMenu(CountryList *countryList) {
    int choice;
    do {
        cout << "\n--- ADD MENU ---\n";
        cout << "1. Add a country\n";
        cout << "2. Add a team to a country\n";
        cout << "3. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: handleAddCountry(countryList);
                break;
            case 2: handleAddTeam(countryList);
                break;
            case 3: return; // Вернуться в главное меню
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

// Подменю для удаления
void removeMenu(CountryList *countryList) {
    int choice;
    do {
        cout << "\n--- REMOVE MENU ---\n";
        cout << "1. Remove a country\n";
        cout << "2. Remove a team from a country\n";
        cout << "3. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: handleRemoveCountry(countryList);
                break;
            case 2: handleRemoveTeam(countryList);
                break;
            case 3: return; // Вернуться в главное меню
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

// Подменю для редактирования
void editMenu(CountryList *countryList) {
    int choice;
    do {
        cout << "\n--- EDIT MENU ---\n";
        cout << "1. Edit a team\n";
        cout << "2. Edit a country\n";
        cout << "3. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: handleEditTeam(countryList);
                break;
            case 2: handleEditCountry(countryList);
                break;
            case 3: return; // Вернуться в главное меню
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

// Главное меню
int mainMenu(CountryList *countryList) {
    int choice;
    do {
        cout << "\n--- MAIN MENU ---\n";
        cout << "1. Load data from files\n";
        cout << "2. Add (Country or Team)\n";
        cout << "3. Remove (Country or Team)\n";
        cout << "4. Edit (Team or Country)\n";
        cout << "5. Search (Team or Country)\n";
        cout << "6. Display countries and teams\n";
        cout << "7. Save data to files\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: handleLoadData(countryList);
                break;
            case 2: addMenu(countryList);
                break;
            case 3: removeMenu(countryList);
                break;
            case 4: editMenu(countryList);
                break;
            case 5: searchMenu(countryList);
                break;
            case 6: CountryList::displayCountries(countryList->getHead());
                break;
            case 7:
                handleSaveData(countryList);
                break;
            case 0: cout << "Exiting...\n";
                break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
