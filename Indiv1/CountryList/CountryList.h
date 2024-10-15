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
private:
    Country *head;


    static int addTeamToCountry(Country *country, const string &teamName, int rank);

    Country *findCountry(const string &countryName) const;

    static Team *findTeam(Country *country, const string &teamName);

    static int getTeamRank(Team *teamList, const string &countryName) ;

public:
    CountryList();

    int addCountry(const string &countryName);

    int addTeam(const string &countryName, const string &teamName, int rank) const;

    int removeCountry(const string &countryName);

    int removeTeam(const string &countryName, const string &teamName) const;

    int editCountry(const string &oldName, const string &newName);

    int editTeam(const string &countryName, const string &oldTeamName, const string &newTeamName, int newRank);

    void displayCountriesAndTeams() const;

    void displayCountry(const string &countryName) const;

    void displayTeam(const string &countryName, const string &teamName) const;

    int loadFromFile(const string &countriesFile, const string &teamsFile);



    int saveToFile(const string &countriesFile, const string &teamsFile) const;
};

#endif // COUNTRYLIST_H
