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
void addFootballerRecursively(PNode *head, Footballer newFootballer) {
    if (*head == nullptr) {
        *head = new Node{newFootballer, nullptr};
    } else {
        addFootballerRecursively(&((*head)->next), newFootballer);
    }
}

// Рекурсивне виведення команди
void printTeamRecursively(PNode head, int index) {
    if (head != nullptr) {
        cout << "Index: " << index << " ";
        printFootballer(&head->footballer);
        cout << endl;
        printTeamRecursively(head->next, index + 1);
    }
}

// Рекурсивний пошук найкращого форварда
void findBestForwardRecursively(PNode head, Footballer *bestForwarder) {
    if (head == nullptr) {
        return;
    }
    if (head->footballer.amplay == FORWARD && head->footballer.goals > bestForwarder->goals) {
        *bestForwarder = head->footballer;
    }
    findBestForwardRecursively(head->next, bestForwarder);
}

// Рекурсивний пошук футболістів з менше ніж 5 матчами
void findLess5GamesRecursively(PNode head, PNode *result) {
    if (head == nullptr) {
        return;
    }
    if (head->footballer.games < 5) {
        addFootballer(result, head->footballer);
    }
    findLess5GamesRecursively(head->next, result);
}

void findLess5GamesMenuRecurs(PNode head) {
    PNode playersLess5 = nullptr;

    findLess5GamesRecursively(head, &playersLess5);

    if (!isEmpty(playersLess5)) {
        cout << "Footballers with less than 5 games:" << endl;
        printTeam(playersLess5);
    } else {
        cout << "No footballers with less than 5 games found." << endl;
    }

    freeMemory(&playersLess5);
}

void addFootballerMenuRecurs(PNode *head) {
    Footballer newFootballer = createFootballer();
    addFootballerRecursively(head, newFootballer);
    writeToFile(*head, FILEPATH); // Зберігаємо зміни у файл
}


void insertBeforeMenuRecurs(PNode *head) {
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
        insertBeforeRecursive(head, newFootballer, targetFootballer);
        writeToFile(*head, FILEPATH); // Зберігаємо зміни у файл
    }
}

void insertAfterMenuRecurs(PNode *head) {
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
        insertAfterRecursive(head, newFootballer, targetFootballer);
        writeToFile(*head, FILEPATH); // Зберігаємо зміни у файл
    }
}

void deleteFootballerMenuRecurs(PNode *head) {
    Footballer footballerToDelete{};
    int choice;
    printTeam(*head);
    cout << "Input index of the footballer you want to delete" << endl;
    cin >> choice;
    PNode temp = *head;
    while (choice > 0 && !isEmpty(temp)) {
        temp = temp->next;
        choice--;
    }
    if (isEmpty(temp)) {
        cout << "Wrong choice";
    } else {
        footballerToDelete = temp->footballer;
        deleteFootballerRecursive(head, footballerToDelete);
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
    cout << "0. Exit" << endl;
    cout << "Entre your choice: ";
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
        case 0:
            break;
        default:
            cout << "Invalid Choice" << endl;
    }
}

void findBestForwardMenuRecurs(PNode head) {
    Footballer bestForward{};
    findBestForwardRecursively(head, &bestForward);

    if (bestForward.goals > 0) {
        cout << "Best Forward:" << endl;
        printFootballer(&bestForward);
    } else {
        cout << "No forwards found." << endl;
    }
}

bool deleteFootballerRecursive(PNode *head, const Footballer &targetFootballer) {
    if (isEmpty(*head)) {
        return false; // Кінець списку, футболіста не знайдено
    }
    if (equals((*head)->footballer, targetFootballer)) {
        PNode temp = *head; // Запам'ятовуємо вузол, що буде видалено
        *head = (*head)->next; // Зміщуємо голову на наступний вузол
        delete temp; // Видаляємо поточний вузол
        return 1 + deleteFootballerRecursive(head, targetFootballer); // Футболіста видалено
    }
    return deleteFootballerRecursive(&(*head)->next, targetFootballer); // Рекурсивно шукаємо далі
}

bool insertBeforeRecursive(PNode *head, const Footballer &newFootballer, const Footballer &targetFootballer) {
    if (isEmpty(*head)) {
        return false; // Кінець списку, футболіста не знайдено
    }
    if (equals((*head)->footballer, targetFootballer)) {
        PNode newNode = new Node{newFootballer, (*head)}; // Створюємо новий вузол перед поточним
        *head = newNode;
        return true;
    }
    return insertBeforeRecursive(&(*head)->next, newFootballer, targetFootballer); // Рекурсивно шукаємо далі
}

bool insertAfterRecursive(PNode *head, const Footballer &newFootballer, const Footballer &targetFootballer) {
    if (isEmpty(*head)) {
        return false; // Кінець списку, футболіста не знайдено
    }
    if (equals((*head)->footballer, targetFootballer)) {
        PNode newNode = new Node{newFootballer, (*head)->next}; // Створюємо новий вузол перед поточним
        (*head)->next = newNode;
        return true;
    }
    return insertAfterRecursive(&(*head)->next, newFootballer, targetFootballer); // Рекурсивно шукаємо далі
}
