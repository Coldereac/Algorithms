#include "functions.h"

using namespace std;

// Функція для додавання нового гравця

int main() {
    Team team{}; // Ініціалізація порожньої команди
/*    Footballer first{"Ivan", FORWARD, 20, 20, 20};
    addFootballer(&team, first);
    addFootballer(&team, {"Johan", GOALKEEPER, 19, 3, 1});*/
    readFromFile(&team, "footballers.bin");
    printTeam(&team);
    writeToFile(&team, "footballers.bin");
    return 0;
}
