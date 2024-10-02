#include "functions.h"
#include "recursion.h"
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
                addMenu(&head);
                break;
            case 2:
                deleteFootballerMenu(&head);
                break;
            case 3:
                cout << "Team:" << endl;
                printTeam(head);
                break;
            case 4:
                findMenu(head);
                break;
            case 5:
                recursionMenu(&head);
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 0);

    freeMemoryRecursively(&head); // Вивільнення пам'яті

    return 0;
}
