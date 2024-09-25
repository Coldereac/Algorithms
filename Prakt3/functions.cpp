#include "functions.h"

#include <cstring>
#include <fstream>

using namespace std;

// Перевірка, чи є список порожнім
bool isEmpty(PNode head) {
    return head == nullptr;
}


// Функція для додавання футболіста до списку
void addFootballer(PNode &head, Footballer newFootballer) {
    auto newNode = new Node{newFootballer, nullptr};
    if (isEmpty(head)) {
        head = newNode;
    } else {
        Node *temp = head;
        while (!isEmpty(temp->next)) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Функція порівняння двох футболістів
bool equals(const Footballer &a, const Footballer &b) {
    return strcmp(a.lastName, b.lastName) == 0 && a.amplay == b.amplay && a.age == b.age &&
           a.goals == b.goals && a.games == b.games;
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
    while (!isEmpty(temp)) {
        cout << "Index: " << counter++ << " ";
        printFootballer(&temp->footballer);
        temp = temp->next;
        cout << endl;
    }
}

// Функція для пошуку кращого нападника
void findBestForwarder(PNode head, Footballer *bestForwarder) {
    PNode temp = head;
    while (!isEmpty(temp)) {
        if (temp->footballer.amplay == FORWARD && bestForwarder->goals < temp->footballer.goals) {
            *bestForwarder = temp->footballer;
        }
        temp = temp->next;
    }
}

// Функція для пошуку футболістів з менше ніж 5 матчами
void findLess5Games(PNode head, PNode &result) {
    PNode temp = head;
    while (!isEmpty(temp)) {
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

    while (!isEmpty(temp) && !equals(temp->footballer, toDelete)) {
        prev = temp;
        temp = temp->next;
    }

    if (isEmpty(temp)) {
        return; // Футболіста не знайдено
    }

    if (isEmpty(prev)) {
        *head = temp->next; // Видаляємо перший елемент
    } else {
        prev->next = temp->next;
    }

    delete temp;
}


// Функція для запису списку у файл
void writeToFile(PNode head, const char *filename) {
    FILE *outFile = fopen(filename, "wb"); // Відкриваємо файл для запису у бінарному форматі
    if (outFile == nullptr) {
        cout << "Error opening file " << filename << endl << "This file will be created" << endl;
        return;
    }

    // Підраховуємо кількість елементів
    int size = 0;
    PNode temp = head;
    while (!isEmpty(temp)) {
        size++;
        temp = temp->next;
    }

    // Записуємо кількість елементів у файл
    fwrite(&size, sizeof(int), 1, outFile);

    // Записуємо дані кожного футболіста у файл
    temp = head;
    while (!isEmpty(temp)) {
        fwrite(&temp->footballer, sizeof(Footballer), 1, outFile);
        temp = temp->next;
    }

    cout << endl << "Writed to file " << filename << endl << endl;
    fclose(outFile); // Закриваємо файл
}

// Функція для читання списку з файлу
void readFromFile(PNode *head, const char *filename) {
    FILE *inFile = fopen(filename, "rb"); // Відкриваємо файл для читання у бінарному форматі
    if (inFile == nullptr) {
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
        addFootballer(*head, footballer); // Додаємо футболіста до списку
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

Footballer createFootballer() {
    Footballer footballer{};
    cout << "Enter footballer's last name: ";
    cin >> footballer.lastName;

    cout << "Enter footballer's amplua (0 - Goalkeeper, 1 - Defender, 2 - Midfielder, 3 - Forward): ";
    int ampluaChoice;
    cin >> ampluaChoice;
    footballer.amplay = AmplayType(ampluaChoice);

    cout << "Enter footballer's age: ";
    cin >> footballer.age;

    cout << "Enter number of games played: ";
    cin >> footballer.games;

    cout << "Enter number of goals scored: ";
    cin >> footballer.goals;
    return footballer;
}

void addFootballerMenu(PNode head) {
    Footballer newFootballer = createFootballer();
    addFootballer(head, newFootballer);
    writeToFile(head, FILEPATH); // Зберігаємо зміни у файл
}

void deleteFootballerMenu(PNode head) {
    Footballer footballerToDelete{};
    int choice;
    printTeam(head);
    cout << "Input index of the footballer you want to delete" << endl;
    cin >> choice;
    PNode temp = head;
    while (choice > 0 && !isEmpty(temp)) {
        temp = temp->next;
        choice--;
    }
    if (isEmpty(temp)) {
        cout << "Wrong choice";
    } else {
        footballerToDelete = temp->footballer;
        deleteFootballer(&head, footballerToDelete);
        writeToFile(head, FILEPATH); // Зберігаємо зміни у файл
    }
}

void freeMemory(PNode *node) {
    while (!isEmpty(*node)) {
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
    PNode playersLess5 = nullptr;

    findLess5Games(head, playersLess5);

    if (!isEmpty(playersLess5)) {
        cout << "Footballers with less than 5 games:" << endl;
        printTeam(playersLess5);
    } else {
        cout << "No footballers with less than 5 games found." << endl;
    }

    freeMemory(&playersLess5);
}



// Вставка нового елемента перед заданим
void insertBefore(PNode *head, Footballer newFootballer, Footballer targetFootballer) {
    auto newNode = new Node{newFootballer, nullptr};
    if (isEmpty(*head)) return;

    if (equals((*head)->footballer, targetFootballer)) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    PNode temp = *head;
    while (!isEmpty(temp->next) && !equals(temp->next->footballer, targetFootballer)) {
        temp = temp->next;
    }

    if (!isEmpty(temp->next)) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertBeforeMenu(PNode *head) {
    Footballer targetFootballer{};
    int choice;
    printTeam(*head);
    cout << "Input index of the footballer you want to insert before" << endl;
    cin >> choice;
    PNode temp = *head;
    while (choice > 0 && !isEmpty(temp)) {
        temp = temp->next;
        choice--;
    }
    if (temp == nullptr) {
        cout << "Wrong choice";
    } else {
        targetFootballer = temp->footballer;
        Footballer newFootballer = createFootballer();
        insertBefore(head, newFootballer, targetFootballer);
        writeToFile(*head, FILEPATH); // Зберігаємо зміни у файл
    }
}

// Вставка нового елемента після заданого
void insertAfter(PNode *head, Footballer newFootballer, Footballer targetFootballer) {
    auto newNode = new Node{newFootballer, nullptr};
    PNode temp = *head;

    while (!isEmpty(temp) && !equals(temp->footballer, targetFootballer)) {
        temp = temp->next;
    }

    if (!isEmpty(temp)) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfterMenu(PNode *head) {
    Footballer targetFootballer{};
    int choice;
    printTeam(*head);
    cout << "Input index of the footballer you want to insert after" << endl;
    cin >> choice;
    PNode temp = *head;
    while (choice > 0 && !isEmpty(temp)) {
        temp = temp->next;
        choice--;
    }
    if (isEmpty(temp)) {
        cout << "Wrong choice";
    } else {
        targetFootballer = temp->footballer;
        Footballer newFootballer = createFootballer();
        insertAfter(head, newFootballer, targetFootballer);
        writeToFile(*head, FILEPATH); // Зберігаємо зміни у файл
    }
}

// Пошук елемента з заданими властивостями
PNode findFootballer(PNode head, Footballer targetFootballer) {
    PNode temp = head;
    PNode founded = nullptr;
    bool found = false;
    while (!isEmpty(temp) && !found) {
        if (equals(temp->footballer, targetFootballer)) {
            founded = temp;
            found = true;
        }
        temp = temp->next;
    }
    return founded;
}

