#include "recursion.h"
#include "functions.h"

using namespace std;

// Рекурсивне видалення всіх елементів списку
void freeMemoryRecursively(PNode *node) {
    if (*node != nullptr) {
        freeMemoryRecursively(&((*node)->next));
        delete *node;
    }
}

// Рекурсивне додавання нового елемента в кінець списку
void addFootballerRecursively(PNode *head, Footballer &newFootballer) {
    if (*head == nullptr) {
        newFootballer.index = 0; // Установити індекс для нового футболіста
        *head = new Node{newFootballer, nullptr};
    } else {
        addFootballerRecursively(&((*head)->next), newFootballer);
        // Оновлення індексу для кожного футболіста
        (*head)->footballer.index = (*head)->next ? (*head)->next->footballer.index + 1 : 1;
    }
}

// Рекурсивне виведення команди
void printTeamRecursively(PNode head) {
    if (head != nullptr) {
        printFootballer(&head->footballer);
        cout << endl;
        printTeamRecursively(head->next);
    }
}

// Рекурсивний пошук найкращого форварда
void findBestForwardRecursively(PNode head, Footballer &bestForwarder) {
    if (isEmpty(head)) {
        return;
    }
    if (head->footballer.amplay == FORWARD && head->footballer.goals > bestForwarder.goals) {
        bestForwarder = head->footballer;
    }
    findBestForwardRecursively(head->next, bestForwarder);
}

// Рекурсивний пошук футболістів з менше ніж 5 матчами
void findLess5GamesRecursively(PNode head, PNode *result) {
    if (head == nullptr) {
        return;
    }
    if (head->footballer.games < 5) {
        Footballer newFootballer = head->footballer;
        newFootballer.index = (isEmpty(*result)) ? 0 : (*result)->footballer.index + 1; // Встановлюємо індекс
        addFootballer(result, newFootballer);
    }
    findLess5GamesRecursively(head->next, result);
}

void findLess5GamesMenuRecurs(PNode head) {
    PNode playersLess5 = nullptr;

    findLess5GamesRecursively(head, &playersLess5);

    if (!isEmpty(playersLess5)) {
        cout << "Footballers with less than 5 games:" << endl;
        printTeamRecursively(playersLess5);
    } else {
        cout << "No footballers with less than 5 games found." << endl;
    }

    freeMemoryRecursively(&playersLess5);
}

void addFootballerMenuRecurs(PNode *head) {
    Footballer newFootballer = createFootballer();
    addFootballerRecursively(head, newFootballer);
    writeToFile(*head, FILEPATH); // Зберігаємо зміни у файл
}

void insertBeforeMenuRecurs(PNode *head) {
    PNode temp;
    findNeededByIndex(head, temp);
    if (temp == nullptr) {
        cout << "Wrong choice" << endl;
    } else {
        Footballer newFootballer = createFootballer();
        insertBeforeRecursive(head, newFootballer, temp->footballer.index);
        refreshIndexes(*head);
        writeToFile(*head, FILEPATH); // Зберігаємо зміни у файл
    }
}

void insertAfterMenuRecurs(PNode *head) {
    PNode temp;
    findNeededByIndex(head, temp);
    if (temp == nullptr) {
        cout << "Wrong choice" << endl;
    } else {
        Footballer newFootballer = createFootballer();
        insertAfterRecursive(head, newFootballer, temp->footballer.index);
        refreshIndexes(*head);
        writeToFile(*head, FILEPATH); // Зберігаємо зміни у файл
    }
}

void findNeededByIndex(PNode *head, PNode &temp) {
    int choice;
    printTeamRecursively(*head);
    cout << "Input index of the footballer you want to use as anchor/ to delete: ";
    cin >> choice;
    temp = *head;
    while (temp != nullptr && temp->footballer.index != choice) {
        temp = temp->next;
    }
}

void deleteFootballerMenuRecurs(PNode *head) {
    PNode temp;
    findNeededByIndex(head, temp);
    if (temp == nullptr) {
        cout << "Wrong choice" << endl;
    } else {
        deleteFootballerRecursive(head, temp->footballer.index);
        refreshIndexes(*head);
        writeToFile(*head, FILEPATH); // Зберігаємо зміни у файл
    }
}

// Меню для вибору рекурсивних функцій
void recursionMenu(PNode *head) {
    int choice = 0;
    cout << "Recursion Menu: " << endl;
    cout << "1. Find Best Forward" << endl;
    cout << "2. Find Less 5 Games" << endl;
    cout << "3. Add footballer" << endl;
    cout << "4. Print Team" << endl;
    cout << "5. Add Footballer before" << endl;
    cout << "6. Add Footballer after" << endl;
    cout << "7. Delete Footballer" << endl;
    cout << "8. Print in reverse" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            findBestForwardMenuRecurs(*head);
            break;
        case 2:
            findLess5GamesMenuRecurs(*head);
            break;
        case 3:
            addFootballerMenuRecurs(head);
            break;
        case 4:
            printTeamRecursively(*head);
            break;
        case 5:
            insertBeforeMenuRecurs(head);
            break;
        case 6:
            insertAfterMenuRecurs(head);
            break;
        case 7:
            deleteFootballerMenuRecurs(head);
            break;
        case 8:
            printReverse(*head);
            break;
        case 0:
            break;
        default:
            cout << "Invalid Choice" << endl;
    }
}

void findBestForwardMenuRecurs(PNode head) {
    Footballer bestForward{};
    findBestForwardRecursively(head, bestForward);

    if (bestForward.goals > 0) {
        cout << "Best Forward:" << endl;
        printFootballer(&bestForward);
    } else {
        cout << "No forwards found." << endl;
    }
}

bool deleteFootballerRecursive(PNode *head, int targetIndex) {
    if (isEmpty(*head)) {
        return false; // Кінець списку, футболіста не знайдено
    }
    if ((*head)->footballer.index == targetIndex) {
        PNode temp = *head; // Запам'ятовуємо вузол, що буде видалено
        *head = (*head)->next; // Зміщуємо голову на наступний вузол
        delete temp; // Видаляємо поточний вузол
        return true; // Футболіста видалено
    }
    return deleteFootballerRecursive(&(*head)->next, targetIndex); // Рекурсивно шукаємо далі
}

bool insertBeforeRecursive(PNode *head, const Footballer &newFootballer, int targetIndex) {
    if (isEmpty(*head)) {
        return false; // Кінець списку, футболіста не знайдено
    }
    if ((*head)->footballer.index == targetIndex) {
        PNode newNode = new Node{newFootballer, (*head)}; // Створюємо новий вузол перед поточним
        *head = newNode;
        return true;
    }
    return insertBeforeRecursive(&(*head)->next, newFootballer, targetIndex); // Рекурсивно шукаємо далі
}

bool insertAfterRecursive(PNode *head, const Footballer &newFootballer, int targetIndex) {
    if (isEmpty(*head)) {
        return false; // Кінець списку, футболіста не знайдено
    }
    if ((*head)->footballer.index == targetIndex) {
        PNode newNode = new Node{newFootballer, (*head)->next}; // Створюємо новий вузол після поточного
        (*head)->next = newNode;
        return true;
    }
    return insertAfterRecursive(&(*head)->next, newFootballer, targetIndex); // Рекурсивно шукаємо далі
}

int printReverse(PNode head){
    if (head != nullptr){
        printReverse(head->next);
        printFootballer(&head->footballer);
    }
    return 0;
}
