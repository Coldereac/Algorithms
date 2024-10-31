#ifndef MENU_H
#define MENU_H

#include "../functions.h"

// Functions for the main menu and its submenus
void loadMenu(Country *&countryList, Team *&teamList);

void saveMenu(Country *countryList, Team *teamList);

void displayMenu(Country *countryList, Team *teamList);

void manageMenu(Country *&countryList, Team *&teamList);

void searchMenu(Country *countryList, Team *teamList);

void sortAndRankMenu(Team *&teamList);

void simulationMenu(Team **teamList, Country **countryList);

void mainMenu();

#endif // MENU_H
