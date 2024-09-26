#include "functions.h"

using namespace std;

int main() {
    PNode head = nullptr;

    readFromFile(&head, FILEPATH); // Завантажуємо дані з файлу

    int choice;
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addFootballerMenu(&head);
                break;
            case 2:
                addManyFootballersMenu(&head);
                break;
            case 3:
                deleteFootballerMenu(&head);
                break;
            case 4:
                cout << "Team:" << endl;
                printTeam(head);
                break;
            case 5:
                findBestForwardMenu(head);
                break;
            case 6:
                findLess5GamesMenu(head);
                break;
            case 7:
                insertBeforeMenu(&head);
                break;
            case 8:
                insertAfterMenu(&head);
                break;
            case 9:
                findFootballerMenu(head);
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 0);

    // Звільняємо пам'ять
    // PNode current = head;
    // while (current != nullptr) {
    //     Node *next = current->next;
    //     delete current;
    //     current = next;
    // }
    freeMemory(&head);

    return 0;
}
