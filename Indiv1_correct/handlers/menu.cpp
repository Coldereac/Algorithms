#include <iostream>
#include "menu.h"

using namespace std;

void loadMenu(Country *&countryList, Team *&teamList) {
    int choice;
    string filename;

    do {
        cout << "\nLoad Data Menu:\n";
        cout << "1. Load countries from file\n";
        cout << "2. Load team ranks from file\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter countries file name: ";
                cin >> filename;
                countryList = loadCountriesFromFile(filename);
                cout << "Countries loaded successfully.\n";
                break;
            case 2:
                cout << "Enter teams file name: ";
                cin >> filename;
                teamList = loadTeamsRanksFromFile(filename);
                cout << "Teams loaded successfully.\n";
                break;
            case 0:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}

void saveMenu(Country *countryList, Team *teamList) {
    int choice;
    string filename;
    do {
        cout << "\nSave Data Menu:\n";
        cout << "1. Save countries to file\n";
        cout << "2. Save team ranks to file\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter destination to save countries file name: ";
                cin >> filename;
                saveCountriesToFile(filename, countryList);
                cout << "Countries saved successfully.\n";
                break;
            case 2:
                cout << "Enter destination to save teams file name: ";
                cin >> filename;
                saveTeamsRanksToFile(filename, teamList);
                cout << "Teams saved successfully.\n";
                break;
            case 0:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}


void displayMenu(Country *countryList, Team *teamList) {
    int choice;
    do {
        cout << "\nDisplay Data Menu:\n";
        cout << "1. Display countries\n";
        cout << "2. Display teams\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayCountryList(countryList);
                break;
            case 2:
                displayTeamList(teamList);
                break;
            case 0:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}


void manageMenu(Country *&countryList, Team *&teamList) {
    int choice;
    string name;
    string countryName;
    Country *temp;
    do {
        cout << "\nManage Data Menu:\n";
        cout << "1. Add a country\n";
        cout << "2. Add a team to a country\n";
        cout << "3. Remove a country\n";
        cout << "4. Remove a team\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter country name to add: ";
                cin >> name;
                addCountry(&countryList, new Country(name));
                cout << "Country added successfully.\n";
                break;
            case 2:
                cout << "Enter country name where to add: ";
                cin >> countryName;
                cout << "Enter team name to add: ";
                cin >> name;
                temp = countryList;
                while (temp != nullptr && temp->name != countryName) {
                    temp = temp->next;
                }
                if (temp == nullptr) {
                    cout << "Error: Country not found.\n";
                    break;
                }
                addTeamInCountry(&temp, &teamList, new Team(name));
                transferRanksAndPoints(&countryList, teamList);
                saveTeamsRanksToFile("/home/malinka/teams.txt", teamList);
                saveCountriesToFile("/home/malinka/countries.txt", countryList);
                teamList = loadTeamsRanksFromFile("/home/malinka/teams.txt");
                countryList = loadCountriesFromFile("/home/malinka/countries.txt");
                cout << "Team added successfully.\n";
                break;
            case 3:
                cout << "Enter country name to remove: ";
                cin >> name;
                deleteCountry(&countryList, name);
                cout << "Country removed successfully.\n";
                break;
            case 4:
                cout << "Enter team name to remove: ";
                cin >> name;
                removeTeamFromTeamList(&teamList, name);
                syncTeams(teamList, &countryList);
                refreshPlacements(&teamList);
                transferRanksAndPoints(&countryList, teamList);
                cout << "Team removed successfully.\n";
                break;
            case 5:
                transferRanksAndPoints(&countryList, teamList);
                cout << "Ranks and Points were transferred successfully.\n";
            case 0:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}


void searchMenu(Country *countryList, Team *teamList) {
    int choice;
    string name;

    do {
        cout << "\nSearch Menu:\n";
        cout << "1. Find team by name\n";
        cout << "2. Find team by rank\n";
        cout << "3. Find teams by points\n";
        cout << "4. Find country by name\n";
        cout << "5. Find country by team name\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter team name to search: ";
                cin >> name;
                displayTeam(findTeamByName(teamList, name));
                break;
            case 2:
                int rank;
                cout << "Enter team rank to search: ";
                cin >> rank;
                displayTeam(findTeamByRank(teamList, rank));
            case 3:
                int min, max;
                cout << "Enter min and max points to search: ";
                cin >> min >> max;
                displayTeamList(findTeamByPoints(teamList, min, max));
            case 4:
                cout << "Enter country name to search: ";
                cin >> name;
                displayCountry(findCountryByName(countryList, name));
                break;
            case 5:
                cout << "Enter team name to search: ";
                cin >> name;
                displayCountry(findCountryByTeam(countryList, name));
                break;
            case 0:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}


void sortAndRankMenu(Team *&teamList) {
    int choice;

    do {
        cout << "\nSort and Rank Menu:\n";
        cout << "1. Sort teams by points\n";
        cout << "2. Refresh team placements\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sortTeamList(&teamList);
                cout << "Teams sorted by points.\n";
                break;
            case 2:
                refreshPlacements(&teamList);
                cout << "Team placements refreshed.\n";
                break;
            case 0:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}


void simulationMenu(Team **teamList, Country **countryList) {
    int choice;

    do {
        cout << "\nSimulation Menu:\n";
        cout << "1. Simulate a round\n";
        cout << "2. Transfer teams to a new round\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                simulateRound(teamList);
                refreshPlacements(teamList);
                transferRanksAndPoints(countryList, *teamList);
                cout << "Round simulated.\n";
                break;
            case 2:
                transferToNewRound(teamList);
                syncTeams(*teamList, countryList);
                deleteCountriesWithoutTeams(countryList);
                transferRanksAndPoints(countryList, *teamList);
                cout << "Teams transferred to a new round.\n";
                break;
            case 0:
                cout << "Returning to Main Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}


void mainMenu() {
    int choice;
    Country *countryList = loadCountriesFromFile(STARTFILECOUNTRIES);
    Team *teamList = loadTeamsRanksFromFile(STARTFILETEAMS);
    transferRanksAndPoints(&countryList, teamList);

    do {
        cout << "\nMain Menu:\n";
        cout << "1. Load Data\n";
        cout << "2. Save Data\n";
        cout << "3. Display Data\n";
        cout << "4. Manage Data\n";
        cout << "5. Search Functions\n";
        cout << "6. Sort and Rank\n";
        cout << "7. Simulation\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                loadMenu(countryList, teamList);
                break;
            case 2:
                saveMenu(countryList, teamList);
                break;
            case 3:
                displayMenu(countryList, teamList);
                break;
            case 4:
                manageMenu(countryList, teamList);
                break;
            case 5:
                searchMenu(countryList, teamList);
                break;
            case 6:
                sortAndRankMenu(teamList);
                break;
            case 7:
                simulationMenu(&teamList, &countryList);
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}
