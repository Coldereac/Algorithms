#ifndef COUNTRYLIST_H
#define COUNTRYLIST_H

#include <string>

using namespace std;

/**
 * Структура для представлення футбольної команди.
 * Містить назву команди, рейтинг та вказівник на наступну команду в списку.
 */
struct Team {
    string name;  // Назва команди
    int rank;     // Рейтинг команди
    Team *next;   // Вказівник на наступну команду

    Team(string n, int r);  // Конструктор для ініціалізації назви та рейтингу команди
};

/**
 * Структура для представлення країни.
 * Містить назву країни, список команд та вказівник на наступну країну в списку.
 */
struct Country {
    string name;     // Назва країни
    Team *teamList;  // Вказівник на список команд у цій країні
    Country *next;   // Вказівник на наступну країну

    Country(const string &n);
    Country(string &n);// Конструктор для ініціалізації назви країни
};

/**
 * Клас для управління списком країн і команд.
 * Забезпечує функціонал додавання, пошуку, редагування та видалення країн і команд.
 */
class CountryList {
    Country *head;  // Вказівник на початок списку країн

    /**
     * Додає команду до країни.
     * @param country Вказівник на країну, до якої додається команда.
     * @param teamName Назва команди.
     * @param rank Рейтинг команди.
     * @return Статус операції (успіх або помилка).
     */
    static int addTeamToCountry(Country *country, const string &teamName, int rank);

    /**
     * Повертає рейтинг команди з даного списку команд.
     * @param teamList Список команд.
     * @param countryName Назва країни.
     * @return Рейтинг команди або код помилки, якщо команда не знайдена.
     */
    static int getTeamRank(Team *teamList, const string &countryName);

public:
    CountryList();  // Конструктор для ініціалізації списку країн

    /**
     * Повертає вказівник на голову списку країн.
     * @return Вказівник на першу країну в списку.
     */
    Country *getHead() const;

    /**
     * Шукає команду за назвою у вказаній країні або у всьому списку.
     * @param teamName Назва команди для пошуку.
     * @param country Вказівник на країну (опціонально).
     * @return Вказівник на знайдену команду або nullptr, якщо не знайдена.
     */
    Team *findTeamByName(const string &teamName, const Country *country = nullptr) const;

    /**
     * Шукає команду за рейтингом у вказаній країні або у всьому списку.
     * @param rank Рейтинг команди.
     * @param country Вказівник на країну (опціонально).
     * @return Вказівник на знайдену команду або nullptr, якщо не знайдена.
     */
    Team *findTeamByRank(int rank, const Country *country = nullptr) const;

    /**
     * Шукає країну за назвою.
     * @param countryName Назва країни для пошуку.
     * @return Вказівник на знайдену країну або nullptr, якщо не знайдена.
     */
    Country *findCountry(const string &countryName) const;

    /**
     * Додає країну до списку.
     * @param countryName Назва країни.
     * @return Статус операції (успіх або помилка).
     */
    int addCountry(const string &countryName);

    /**
     * Додає команду до зазначеної країни.
     * @param countryName Назва країни.
     * @param teamName Назва команди.
     * @param rank Рейтинг команди.
     * @return Статус операції (успіх або помилка).
     */
    int addTeam(const string &countryName, const string &teamName, int rank) const;

    /**
     * Видаляє країну зі списку.
     * @param countryName Назва країни для видалення.
     * @return Статус операції (успіх або помилка).
     */
    int removeCountry(const string &countryName);

    /**
     * Видаляє команду з зазначеної країни.
     * @param countryName Назва країни.
     * @param teamName Назва команди для видалення.
     * @return Статус операції (успіх або помилка).
     */
    int removeTeam(const string &countryName, const string &teamName) const;

    /**
     * Редагує назву країни.
     * @param oldName Старе ім'я країни.
     * @param newName Нове ім'я країни.
     * @return Статус операції (успіх або помилка).
     */
    int editCountry(const string &oldName, const string &newName);

    /**
     * Редагує назву команди.
     * @param newTeamName Нова назва команди.
     * @param team Вказівник на команду для редагування.
     * @return Статус операції (успіх або помилка).
     */
    static int editTeamName(const string &newTeamName, Team *team);

    /**
     * Редагує рейтинг команди.
     * @param newRank Новий рейтинг команди.
     * @param team Вказівник на команду для редагування.
     * @return Статус операції (успіх або помилка).
     */
    static int editTeamRank(int newRank, Team *team);

    /**
     * Виводить на екран інформацію про всі країни в списку.
     * @param head Вказівник на голову списку країн.
     */
    static void displayCountries(Country *head);

    /**
     * Виводить на екран інформацію про одну країну.
     * @param country Вказівник на країну для відображення.
     */
    static void displayCountry(Country *country);

    /**
     * Виводить на екран інформацію про одну команду.
     * @param team Вказівник на команду для відображення.
     */
    static void displayTeam(Team *team);

    /**
     * Завантажує дані з файлів про країни та команди.
     * @param countriesFile Шлях до файлу з країнами.
     * @param teamsFile Шлях до файлу з командами.
     * @return Статус операції (успіх або помилка).
     */
    int loadFromFile(const string &countriesFile, const string &teamsFile);

    /**
     * Зберігає дані про країни та команди до файлів.
     * @param countriesFile Шлях до файлу з країнами.
     * @param teamsFile Шлях до файлу з командами.
     * @return Статус операції (успіх або помилка).
     */
    int saveToFile(const string &countriesFile, const string &teamsFile) const;

    /**
     * Перераховує рейтинги команд у списку країн.
     */
    void recalculateRanks() const;
};

#endif // COUNTRYLIST_H
