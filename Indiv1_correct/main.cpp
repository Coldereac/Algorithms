//
// Created by malinka on 30.10.24.
//
#include "functions.h"

int main() {
    Country *countryList = nullptr;
    Team *teamList = nullptr;
    try {
        countryList = loadCountriesFromFile(STARTFILECOUNTRIES);
        teamList = loadTeamsRanksFromFile(STARTFILETEAMS);
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    simulateRound(&teamList);
    justifyRanksAndPoints(&countryList, teamList);
    displayCountryList(countryList);
    cout << endl;
    refreshPlacements(&teamList);
    justifyRanksAndPoints(&countryList, teamList);
    displayCountryList(countryList);
    cout << endl;
    displayTeamList(teamList);
    cout << endl;
    transferToNewRound(&teamList);
    justifyRanksAndPoints(&countryList, teamList);
    displayTeamList(teamList);
    cout << endl;
    syncTeams(teamList, &countryList);
    displayCountryList(countryList);
    cout << endl;
    deleteCountriesWithoutTeams(&countryList);
    displayCountryList(countryList);
    cout << endl;
    simulateRound(&teamList);
    refreshPlacements(&teamList);
    justifyRanksAndPoints(&countryList, teamList);
    addTeamInCountry(&countryList, &teamList, new Team("Bober"));
    refreshPlacements(&teamList);
    justifyRanksAndPoints(&countryList, teamList);
    displayTeamList(teamList);
    cout << endl;
    displayCountryList(countryList);
    cout << endl;
    addCountry(&countryList, new Country("TestCountry"));
    displayCountryList(countryList);
    cout << endl;
    return 0;
}
