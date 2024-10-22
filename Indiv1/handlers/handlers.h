//
// Created by malinka on 09.10.24.
//

#ifndef HANDLERS_H
#define HANDLERS_H
#include "../CountryList/CountryList.h"
#include <iostream>
#include <string>

#define COUNTRIESFILE "textFiles/countries.txt"  // Шлях до файлу з даними про країни
#define TEAMSFILE "textFiles/teams.txt"          // Шлях до файлу з даними про команди

/**
 * Завантажує дані з файлів до списку країн.
 * @param countryList Вказівник на список країн.
 */
void handleLoadData(CountryList *countryList);

/**
 * Додає нову країну до списку країн.
 * @param countryList Вказівник на список країн.
 */
void handleAddCountry(CountryList *countryList);

/**
 * Додає нову команду до країни зі списку країн.
 * @param countryList Вказівник на список країн.
 */
void handleAddTeam(const CountryList *countryList);

/**
 * Видаляє країну зі списку країн.
 * @param countryList Вказівник на список країн.
 */
void handleRemoveCountry(CountryList *countryList);

/**
 * Видаляє команду з відповідної країни у списку країн.
 * @param countryList Вказівник на список країн.
 */
void handleRemoveTeam(const CountryList *countryList);

/**
 * Редагує дані команди в країні.
 * @param countryList Вказівник на список країн.
 */
void handleEditTeam(CountryList *countryList);

/**
 * Редагує дані країни у списку країн.
 * @param countryList Вказівник на список країн.
 */
void handleEditCountry(CountryList *countryList);

/**
 * Знаходить і відображає команду за критерієм пошуку.
 * @param countryList Вказівник на список країн.
 */
void findTeam(CountryList *countryList);

/**
 * Знаходить і відображає країну за критерієм пошуку.
 * @param countryList Вказівник на список країн.
 */
void findCountry(CountryList *countryList);

/**
 * Зберігає дані зі списку країн до файлів.
 * @param countryList Вказівник на список країн.
 */
void handleSaveData(const CountryList *countryList);

/**
 * Відображає головне меню та обробляє вибір користувача.
 * @param countryList Вказівник на список країн.
 */
int mainMenu(CountryList *countryList);

#endif //HANDLERS_H
