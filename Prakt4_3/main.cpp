#include <iostream>
#include "functions.h"

using namespace std;


// Головна функція для тестування
int main() {
    PNode head = nullptr;
    int size;
    cout << "Input size to create ordered list: ";
    cin >> size;
    createOrderedList(&head, size);
    cout << "Список після вставок: ";
    printList(head);

    int numberToDelete;
    cout << "Enter number to delete: ";
    cin >> numberToDelete;
    deleteNode(&head, numberToDelete);
    cout << "Список після видалення " << numberToDelete << ": ";
    printList(head);


    return 0;
}
