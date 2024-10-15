#include "handlers.h"

using namespace std;

void handleLoadData(CountryList &countryList) {
    if (countryList.loadFromFile(COUNTRIESFILE, TEAMSFILE) == 0) {
        cout << "Data loaded successfully.\n";
    } else {
        cout << "Error loading data.\n";
    }
}

void handleAddCountry(CountryList &countryList) {
    string countryName;
    cout << "Enter country name: ";
    cin >> countryName;
    if (countryList.addCountry(countryName) == 0) {
        cout << "Country added successfully.\n";
    } else {
        cout << "Error: Country already exists.\n";
    }
}

void handleAddTeam(const CountryList &countryList) {
    string countryName, teamName;
    int rank;
    cout << "Enter country name: ";
    cin >> countryName;
    cout << "Enter team name: ";
    cin >> teamName;
    cout << "Enter team rank: ";
    cin >> rank;
    if (countryList.addTeam(countryName, teamName, rank) == 0) {
        cout << "Team added successfully.\n";
    } else {
        cout << "Error: Could not add team.\n";
    }
}

void handleRemoveCountry(CountryList &countryList) {
    string countryName;
    cout << "Enter country name to remove: ";
    cin >> countryName;
    if (countryList.removeCountry(countryName) == 0) {
        cout << "Country removed successfully.\n";
    } else {
        cout << "Error: Country not found.\n";
    }
}

void handleRemoveTeam(const CountryList &countryList) {
    string countryName, teamName;
    cout << "Enter country name: ";
    cin >> countryName;
    cout << "Enter team name to remove: ";
    cin >> teamName;
    if (countryList.removeTeam(countryName, teamName) == 0) {
        cout << "Team removed successfully.\n";
    } else {
        cout << "Error: Team not found.\n";
    }
}

void handleDisplayCountriesAndTeams(const CountryList &countryList) {
    countryList.displayCountriesAndTeams();
}

void handleEditCountry(CountryList& countryList) {
    string oldName, newName;
    cout << "Enter the current country name: ";
    cin >> oldName;
    cout << "Enter the new country name: ";
    cin >> newName;
    if (countryList.editCountry(oldName, newName) == 0) {
        cout << "Country updated successfully.\n";
    } else {
        cout << "Error: Country not found.\n";
    }
}

void handleEditTeam(CountryList& countryList) {
    string countryName, oldTeamName, newTeamName;
    int newRank;
    cout << "Enter the country name: ";
    cin >> countryName;
    cout << "Enter the current team name: ";
    cin >> oldTeamName;
    cout << "Enter the new team name: ";
    cin >> newTeamName;
    cout << "Enter the new team rank: ";
    cin >> newRank;
    if (countryList.editTeam(countryName, oldTeamName, newTeamName, newRank) == 0) {
        cout << "Team updated successfully.\n";
    } else {
        cout << "Error: Team or country not found.\n";
    }

}


void handleSaveData(const CountryList &countryList) {
    if (countryList.saveToFile(COUNTRIESFILE, TEAMSFILE) == 0) {
        cout << "Data saved successfully.\n";
    } else {
        cout << "Error saving data.\n";
    }
}

int printMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Load data from files\n";
    cout << "2. Add a country\n";
    cout << "3. Add a team to a country\n";
    cout << "4. Remove a country\n";
    cout << "5. Remove a team from a country\n";
    cout << "6. Display countries and teams\n";
    cout << "7. Save data to files\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}
