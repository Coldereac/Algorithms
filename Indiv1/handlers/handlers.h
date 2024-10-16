//
// Created by malinka on 09.10.24.
//

#ifndef HANDLERS_H
#define HANDLERS_H
#include "../CountryList/CountryList.h"
#include <iostream>
#include <string>

#define COUNTRIESFILE "textFiles/countries.txt"
#define TEAMSFILE "textFiles/teams.txt"


void handleLoadData(CountryList *countryList);

void handleAddCountry(CountryList *countryList);

void handleAddTeam(const CountryList *countryList);

void handleRemoveCountry(CountryList *countryList);

void handleRemoveTeam(const CountryList *countryList);

void handleEditTeam(CountryList *countryList);

void handleEditCountry(CountryList *countryList);

void findTeam(CountryList *countryList);

void findCountry(CountryList *countryList);

void handleSaveData(const CountryList *countryList);

int mainMenu(CountryList *countryList);


#endif //HANDLERS_H
