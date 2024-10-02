#include "functions.h"

#include <cstring>
#include <fstream>

using namespace std;

// Перевірка, чи є список порожнім
bool isEmpty(PNode head) {
    return head == nullptr;
}

void refreshIndexes(PNode head, int startIndex) {
    int index = startIndex; // Початкове значення індексу
    PNode temp = head;
    while (temp != nullptr) {
        temp->footballer.index = index++; // Оновлюємо індекс для футболіста
        temp = temp->next; // Переходимо до наступного вузла
    }
}

// Функція для додавання футболіста до списку
void addFootballer(PNode *head, Footballer newFootballer) {
    auto newNode = new Node{newFootballer, nullptr};
    if (isEmpty(*head)) {
        *head = newNode;
        newNode->footballer.index = 0; // Задаємо індекс 0 для першого футболіста
    } else {
        Node *temp = *head;
        int indexCounter = 0;
        while (!isEmpty(temp->next)) {
            temp = temp->next;
            indexCounter++;
        }
        indexCounter++; // Наступний індекс
        newNode->footballer.index = indexCounter; // Задаємо новий індекс
        temp->next = newNode;
    }
}

void addManyFootballers(PNode *head, int amount) {
    for (int i = 0; i < amount; i++) {
        addFootballerMenu(head);
    }
}

void addManyFootballersMenu(PNode *head) {
    int amount = 0;
    cout << "Input amount of Footballers you want to add: ";
    cin >> amount;
    if (amount > 0) {
        addManyFootballers(head, amount);
    } else {
        cout << "Wrong input. Please try again." << endl;
    }
}

// Функція порівняння двох футболістів
bool equals(const Footballer &a, const Footballer &b) {
    return strcmp(a.lastName, b.lastName) == 0 && a.amplay == b.amplay && a.age == b.age &&
           a.goals == b.goals && a.games == b.games;
}

// Функція для виведення інформації про футболіста
void printFootballer(Footballer *footballer) {
    cout << "Index: " << footballer->index;
    cout << " Name: " << footballer->lastName << " Amplua: ";
    outputAmplua(footballer->amplay);
    cout << " Age: " << footballer->age
            << " Number of games: " << footballer->games
            << " Number of goals: " << footballer->goals << endl;
}

// Функція для виведення всієї команди
void printTeam(PNode head) {
    PNode temp = head;
    while (!isEmpty(temp)) {
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
void findLess5Games(PNode head, PNode *result) {
    PNode temp = head;
    while (!isEmpty(temp)) {
        if (temp->footballer.games < 5) {
            addFootballer(result, temp->footballer);
        }
        temp = temp->next;
    }
}

// Функція для видалення футболіста зі списку
void deleteFootballer(PNode *head, int index) {
    PNode temp = *head;
    PNode prev = nullptr;

    while (!isEmpty(temp) && temp->footballer.index != index) {
        prev = temp;
        temp = temp->next;
    }

    if (isEmpty(temp)) {
        return; // Футболіста не знайдено
    }

    if (isEmpty(prev)) {
        *head = temp->next; // Видаляємо перший елемент
        refreshIndexes(*head, 0);
    } else {
        prev->next = temp->next;
        refreshIndexes(prev->next, index);
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
        cout << "This file will be created" << endl;
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
    cout << endl << "Read from file " << filename << endl;
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
    cout << "1. Add" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Print Team" << endl;
    cout << "4. Find" << endl;
    cout << "5. Recursion versions of functions" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

void addMenu(PNode *head) {
    int choice;
    cout << "1. Add Footballer in the end of list" << endl;
    cout << "2. Insert Footballer after another" << endl;
    cout << "3. Insert Footballer before another" << endl;
    cout << "4. Add many Footballers" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            addFootballerMenu(head);
            break;
        case 2:
            insertAfterMenu(head);
            break;
        case 3:
            insertBeforeMenu(head);
            break;
        case 4:
            addManyFootballersMenu(head);
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice" << endl;
    }
}

void findMenu(PNode head) {
    int choice;
    cout << "1. Find Footballer by all his params" << endl;
    cout << "2. Find best Forward" << endl;
    cout << "3. Find Footballers with less than 5 games" << endl;
    cout << "0. Exit" << endl;
    cout << "Input your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            findFootballerMenu(head);
            break;
        case 2:
            findBestForwardMenu(head);
            break;
        case 3:
            findLess5GamesMenu(head);
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice" << endl;
    }
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

void addFootballerMenu(PNode *head) {
    Footballer newFootballer = createFootballer();
    addFootballer(head, newFootballer);
    writeToFile(*head, FILEPATH); // Зберігаємо зміни у файл
}

void deleteFootballerMenu(PNode *head) {
    int choice;
    printTeam(*head);
    cout << "Input index of the footballer you want to delete" << endl;
    cin >> choice;
    deleteFootballer(head, choice);
    writeToFile(*head, FILEPATH);
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

    findLess5Games(head, &playersLess5);

    if (!isEmpty(playersLess5)) {
        cout << "Footballers with less than 5 games:" << endl;
        printTeam(playersLess5);
    } else {
        cout << "No footballers with less than 5 games found." << endl;
    }

    freeMemory(&playersLess5);
}


// Вставка нового елемента перед заданим
void insertBefore(PNode *head, Footballer newFootballer, int targetIndex) {
    auto newNode = new Node{newFootballer, nullptr};
    if (isEmpty(*head)) return;

    if ((*head)->footballer.index == targetIndex) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    PNode temp = *head;
    while (!isEmpty(temp->next) && temp->next->footballer.index != targetIndex) {
        temp = temp->next;
    }

    if (!isEmpty(temp->next)) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertBeforeMenu(PNode *head) {
    int choice;
    printTeam(*head);
    cout << "Input index of the footballer you want to insert before" << endl;
    cin >> choice;
    Footballer newFootballer = createFootballer();
    insertBefore(head, newFootballer, choice);
    refreshIndexes(*head);
    writeToFile(*head, FILEPATH);
}

// Вставка нового елемента після заданого

void insertAfter(PNode *head, Footballer newFootballer, int targetIndex) {
    auto newNode = new Node{newFootballer, nullptr};
    PNode temp = *head;

    while (!isEmpty(temp) && temp->footballer.index != targetIndex) {
        temp = temp->next;
    }

    if (!isEmpty(temp)) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfterMenu(PNode *head) {
    int choice;
    printTeam(*head);
    cout << "Input index of the footballer you want to insert after" << endl;
    cin >> choice;
    Footballer newFootballer = createFootballer();
    insertAfter(head, newFootballer, choice);
    refreshIndexes(*head);
    writeToFile(*head, FILEPATH);
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

void findFootballerMenu(PNode head) {
    Footballer targetFootballer{};
    cout << "Enter footballer's last name: ";
    cin >> targetFootballer.lastName;

    cout << "Enter footballer's amplua (0 - Goalkeeper, 1 - Defender, 2 - Midfielder, 3 - Forward): ";
    int ampluaChoice;
    cin >> ampluaChoice;
    targetFootballer.amplay = AmplayType(ampluaChoice);

    cout << "Enter footballer's age: ";
    cin >> targetFootballer.age;

    cout << "Enter number of games played: ";
    cin >> targetFootballer.games;

    cout << "Enter number of goals scored: ";
    cin >> targetFootballer.goals;
    PNode founded = findFootballer(head, targetFootballer);
    if (!isEmpty(founded)) {
        printFootballer(&founded->footballer);
    } else {
        cout << "Footballer not found" << endl;
    }
}
