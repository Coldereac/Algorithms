#ifndef COUNTRYLIST_H
#define COUNTRYLIST_H

#include <string>

using namespace std;

struct Team {
    string name;
    int rank;
    Team *next;

    Team(string n, int r);
};

struct Country {
    string name;
    Team *teamList;
    Country *next;

    Country(string n);
};

class CountryList {
    Country *head;

    static int addTeamToCountry(Country *country, const string &teamName, int rank);

    static int getTeamRank(Team *teamList, const string &countryName);

public:
    CountryList();

    Country *getHead() const;

    Team *findTeamByName(const string &teamName, const Country *country = nullptr) const;

    Team *findTeamByRank(int rank, const Country *country = nullptr) const;

    Country *findCountry(const string &countryName) const;

    int addCountry(const string &countryName);

    int addTeam(const string &countryName, const string &teamName, int rank) const;

    int removeCountry(const string &countryName);

    int removeTeam(const string &countryName, const string &teamName) const;

    int editCountry(const string &oldName, const string &newName);

    static int editTeamName(const string &newTeamName, Team *team);

    static int editTeamRank(int newRank, Team *team);

    static void displayCountries(Country *head);

    static void displayCountry(Country *country);

    static void displayTeam(Team *team);

    int loadFromFile(const string &countriesFile, const string &teamsFile);

    int saveToFile(const string &countriesFile, const string &teamsFile) const;

    void recalculateRanks() const;
};

#endif // COUNTRYLIST_H
