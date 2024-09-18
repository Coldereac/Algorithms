#include "functions.h"

using namespace std;

int main() {
    Team team{};
    readFromFile(&team, "Prakt0/footballers.bin");
    // addFootballer(&team, {"Ivan", FORWARD, 20, 20, 20});
    // addFootballer(&team, {"Ivaw", FORWARD, 20, 20, 21});
 // addFootballer(&team, {"Johan", GOALKEEPER, 20, 3, 1});
 //   addFootballer(&team, {"Han", GOALKEEPER, 20, 2, 1});
    cout << "Team" << endl;
    printTeam(&team);
    Footballer bestForward{};
    findBestForwarder(&team, &bestForward);
    cout << "Best Forward" << endl;
    printFootballer(&bestForward);
    cout << "Less than 5 games" << endl;
    Team playersWithLessThan5Games{};
    findLess5Games(&team, &playersWithLessThan5Games);
    printTeam(&playersWithLessThan5Games);
    writeToFile(&team, "Prakt0/footballers.bin");
    delete [] team.players;
    return 0;
}
