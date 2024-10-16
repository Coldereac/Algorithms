#include <iostream>
#include "CountryList/CountryList.h"
#include "handlers/handlers.h"

using namespace std;


int main() {
    CountryList countryList;
    int choice;

    do {
        choice = printMenu();

        switch (choice) {
            case 1:
                handleLoadData(&countryList);
                break;
            case 2:
                handleAddCountry(&countryList);
                break;
            case 3:
                handleAddTeam(&countryList);
                break;
            case 4:
                handleRemoveCountry(&countryList);
                break;
            case 5:
                handleRemoveTeam(&countryList);
                break;
            case 6:
                handleDisplayCountriesAndTeams(&countryList);
                break;
            case 7:
                handleSaveData(&countryList);
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
