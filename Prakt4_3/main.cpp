#include <iostream>
#include "functions.h"

using namespace std;


// Головна функція для тестування
int main() {
    PNode head = new Node{0, new Node{100, nullptr}};
    int size;
    cout << "Input size to create ordered list: ";
    cin >> size;
    createOrderedList(&head, size);
    cout << "List after insertion: ";
    printList(head);

    int numberToDelete;
    do {
        cout << "Enter number to delete(1-99): ";
        cin >> numberToDelete;
        if (numberToDelete < 1 || numberToDelete > 99) {
            cout << "Invalid input, try again." << endl;
        }
    } while (numberToDelete < 1 || numberToDelete > 99);
    deleteNode(&head, numberToDelete);
    cout << "List after deletion " << numberToDelete << ": ";
    printList(head);


    return 0;
}
