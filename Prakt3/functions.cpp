#include "functions.h"

#include <cstring>
#include <fstream>

using namespace std;

// Функція для додавання футболіста до списку
void addFootballer(PNode &head, Footballer newFootballer) {
    auto newNode = new Node{newFootballer, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Функція порівняння двох футболістів
bool equals(const Footballer *a, const Footballer *b) {
    return strcmp(a->lastName, b->lastName) == 0 && a->amplay == b->amplay && a->age == b->age &&
           a->goals == b->goals && a->games == b->games;
}

// Функція для виведення інформації про футболіста
void printFootballer(Footballer *footballer) {
    cout << "Name: " << footballer->lastName << " Amplua: ";
    outputAmplua(footballer->amplay);
    cout << " Age: " << footballer->age
            << " Number of games: " << footballer->games
            << " Number of goals: " << footballer->goals << endl;
}

// Функція для виведення всієї команди
void printTeam(PNode head) {
    PNode temp = head;
    int counter = 0;
    while (temp != nullptr) {
        cout << "Index: " << counter++ << " ";
        printFootballer(&temp->footballer);
        temp = temp->next;
        cout << endl;
    }
}

// Функція для пошуку кращого нападника
void findBestForwarder(PNode head, Footballer *bestForwarder) {
    PNode temp = head;
    while (temp != nullptr) {
        if (temp->footballer.amplay == FORWARD && bestForwarder->goals < temp->footballer.goals) {
            *bestForwarder = temp->footballer;
        }
        temp = temp->next;
    }
}

// Функція для пошуку футболістів з менше ніж 5 матчами
void findLess5Games(PNode head, PNode &result) {
    PNode temp = head;
    while (temp != nullptr) {
        if (temp->footballer.games < 5) {
            addFootballer(result, temp->footballer);
        }
        temp = temp->next;
    }
}

// Функція для видалення футболіста зі списку
void deleteFootballer(PNode *head, Footballer toDelete) {
    PNode temp = *head;
    PNode prev = nullptr;

    while (temp != nullptr && !equals(&temp->footballer, &toDelete)) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        return; // Футболіста не знайдено
    }

    if (prev == nullptr) {
        *head = temp->next; // Видаляємо перший елемент
    } else {
        prev->next = temp->next;
    }

    delete temp;
}


// Функція для запису списку у файл
void writeToFile(PNode head, const char *filename) {
    FILE *outFile = fopen(filename, "wb"); // Відкриваємо файл для запису у бінарному форматі
    if (outFile == NULL) {
        cout << "Error opening file " << filename << endl << "This file will be created" << endl;
        return;
    }

    // Підраховуємо кількість елементів
    int size = 0;
    PNode temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    // Записуємо кількість елементів у файл
    fwrite(&size, sizeof(int), 1, outFile);

    // Записуємо дані кожного футболіста у файл
    temp = head;
    while (temp != NULL) {
        fwrite(&temp->footballer, sizeof(Footballer), 1, outFile);
        temp = temp->next;
    }

    cout << endl << "Writed to file " << filename << endl << endl;
    fclose(outFile); // Закриваємо файл
}

// Функція для читання списку з файлу
void readFromFile(PNode &head, const char *filename) {
    FILE *inFile = fopen(filename, "rb"); // Відкриваємо файл для читання у бінарному форматі
    if (inFile == NULL) {
        cout << "Error opening file " << filename << endl;
        return;
    }

    int size = 0;
    // Читаємо кількість елементів зі списку
    fread(&size, sizeof(int), 1, inFile);

    // Читаємо дані кожного футболіста і додаємо до списку
    for (int i = 0; i < size; i++) {
        Footballer footballer{};
        fread(&footballer, sizeof(Footballer), 1, inFile);
        addFootballer(head, footballer); // Додаємо футболіста до списку
    }
    cout << endl << "Readed from file " << filename << endl;
    fclose(inFile); // Закриваємо файл
}


// Функція для виведення амплуа
void outputAmplua(AmplayType amplayType) {
    switch (amplayType) {
        case GOALKEEPER:
            cout << "Goalkeeper";
            break;
        case DEFENDER:
            cout << "Defender";
            break;
        case MIDFIELDER:
            cout << "Midfielder";
            break;
        case FORWARD:
            cout << "Forward";
            break;
    }
}

void printMenu() {
    cout << "Menu:" << endl;
    cout << "1. Add Footballer" << endl;
    cout << "2. Delete Footballer" << endl;
    cout << "3. Print Team" << endl;
    cout << "4. Find Best Forward" << endl;
    cout << "5. Find Footballers with Less Than 5 Games" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

void addFootballerMenu(PNode &head) {
    Footballer newFootballer{};

    cout << "Enter footballer's last name: ";
    cin >> newFootballer.lastName;

    cout << "Enter footballer's amplua (0 - Goalkeeper, 1 - Defender, 2 - Midfielder, 3 - Forward): ";
    int ampluaChoice;
    cin >> ampluaChoice;
    newFootballer.amplay = AmplayType(ampluaChoice);

    cout << "Enter footballer's age: ";
    cin >> newFootballer.age;

    cout << "Enter number of games played: ";
    cin >> newFootballer.games;

    cout << "Enter number of goals scored: ";
    cin >> newFootballer.goals;


    addFootballer(head, newFootballer);
    writeToFile(head, FILEPATH); // Зберігаємо зміни у файл
}

void deleteFootballerMenu(PNode *head) {
    Footballer footballerToDelete{};
    int choice;
    printTeam(*head);
    cout << "Input index of the footballer you want to delete" << endl;
    cin >> choice;
    PNode temp = *head;
    while (choice > 0 && temp != nullptr) {
        temp = temp->next;
        choice--;
    }
    if (temp == nullptr) {
        cout << "Wrong choice";
    } else {
        footballerToDelete = temp->footballer;
        deleteFootballer(head, footballerToDelete);
        writeToFile(*head, FILEPATH); // Зберігаємо зміни у файл
    }

    // cout << "Enter footballer's last name to delete: ";
    // cin >> footballerToDelete.lastName;
    //
    // cout << "Enter footballer's amplua (0 - Goalkeeper, 1 - Defender, 2 - Midfielder, 3 - Forward): ";
    // int ampluaChoice;
    // cin >> ampluaChoice;
    // footballerToDelete.amplay = AmplayType(ampluaChoice);
    //
    // cout << "Enter footballer's age: ";
    // cin >> footballerToDelete.age;
    //
    // cout << "Enter number of games played: ";
    // cin >> footballerToDelete.games;
    //
    // cout << "Enter number of goals scored: ";
    // cin >> footballerToDelete.goals;
}

void freeMemory(PNode *node) {
    while (*node != nullptr) {
        PNode temp = *node;
        *node = (*node)->next;
        delete temp;
    }
}


void findBestForwardMenu(PNode head) {
    Footballer bestForward{};
    findBestForwarder(head, &bestForward);

    if (bestForward.goals > 0) {
        cout << "Best Forward:" << endl;
        printFootballer(&bestForward);
    } else {
        cout << "No forwards found." << endl;
    }
}

void findLess5GamesMenu(PNode head) {
    PNode playersWithLessThan5Games = nullptr;

    findLess5Games(head, playersWithLessThan5Games);

    if (playersWithLessThan5Games != nullptr) {
        cout << "Footballers with less than 5 games:" << endl;
        printTeam(playersWithLessThan5Games);
    } else {
        cout << "No footballers with less than 5 games found." << endl;
    }

    // Очищаємо список з результатами
    // while (playersWithLessThan5Games != nullptr) {
    //     PNode temp = playersWithLessThan5Games;
    //     playersWithLessThan5Games = playersWithLessThan5Games->next;
    //     delete temp;
    // }
    freeMemory(&playersWithLessThan5Games);
}
