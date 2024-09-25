#include <cstdio>
#include <iostream>

#include "../header.h"
using namespace std;

int main() {
    int choice;
    bool work = true;
    pnode head = NULL;
    while (work) {
        printf("1. LIFO 1\n2. LIFO 2\n3. FIFO\n4. Exit\n");
        printf("Enter choice: ");
        cin >> choice;
        switch (choice) {
            case 1: head = formLIFO_1();
                break;
            case 2: formLIFO_2(&head);
                break;
            case 3: head = formFIFO();
                break;
            case 4: work = false;
                break;
            default: printf("Invalid choice\n");
        }
    }
}
