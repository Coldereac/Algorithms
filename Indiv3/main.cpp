#include "functions.h"
//
// Created by malinka on 20.11.24.
//
#include <iostream>
#include "functions.h"
using namespace std;

void printMenu() {
    cout << "1. Load from file" << endl;
    cout << "2. Save to file" << endl;
    cout << "3. Add task" << endl;
    cout << "4. Remove task" << endl;
    cout << "5. Review task(s)" << endl;
    cout << "6. Print number of tasks in queue in the moment" << endl;
    cout << "0. Exit" << endl;
}

void printAddMenu() {
    cout << "1. Add normal task(to the end of the queue)" << endl;
    cout << "2. Add important task(to the beginning of the queue)" << endl;
    cout << "0. Exit" << endl;
}

void printRemoveMenu() {
    cout << "1. Remove completed task(from the beginning of the queue)" << endl;
    cout << "2. Remove old/unnecessary task(from the end of the queue)" << endl;
    cout << "3. Remove task by index" << endl;
    cout << "4. Remove task by task" << endl;
    cout << "5. Remove task by priority" << endl;
    cout << "0. Exit" << endl;
}

void printReviewMenu() {
    cout << "1. Show first task" << endl;
    cout << "2. Show last task" << endl;
    cout << "3. Show all tasks" << endl;
    cout << "0. Exit" << endl;
}


int main() {
    Deque deque;
    int choice;
    char input;
    int number;
    string task;
    do {
        printMenu();
        cout << "Input your choice: ";
        cin >> choice;
        try {
            switch (choice) {
                case 1:
                    cout << "Dou you want to load from standard file?[y/n]";
                    cin >> input;
                    if (input == 'y' || input == 'Y') {
                        deque.loadFromFile(DATA_STANDARD_PATH);
                    } else {
                        cout << "Input file path: ";
                        string path;
                        cin >> path;
                        deque.loadFromFile(path);
                    }
                    cout << "Data loaded" << endl;
                    break;
                case 2:
                    cout << "Dou you want to save to standard file?[y/n]";
                    cin >> input;
                    if (input == 'y' || input == 'Y') {
                        deque.saveToFile(DATA_STANDARD_PATH);
                    } else {
                        cout << "Input file path: ";
                        string path;
                        cin >> path;
                        deque.saveToFile(path);
                    }
                    cout << "Data saved" << endl;
                    break;
                case 3:
                    printAddMenu();
                    cin >> input;
                    switch (input) {
                        case '1':
                            cout << "Input task you want to add: " << endl;
                            getchar();
                            getline(cin, task);
                            deque.addNormalTask(task);
                            cout << "Task added" << endl;
                            break;
                        case '2':
                            cout << "Input task you want to add: " << endl;
                            getchar();
                            getline(cin, task);
                            deque.addImportantTask(task);
                            cout << "Task added" << endl;
                            break;
                        case '0':
                            cout << "Returning to main menu" << endl;
                            break;
                        default:
                            cout << "Input error" << endl;
                    }
                    break;
                case 4:
                    printRemoveMenu();
                    cin >> input;
                    switch (input) {
                        case '1':
                            if (deque.removeFront()) {
                                cout << "Task removed" << endl;
                            } else {
                                cout << "Task wasn't found" << endl;
                            }
                            break;
                        case '2':
                            if (deque.removeBack()) {
                                cout << "Task removed" << endl;
                            } else {
                                cout << "Task wasn't found" << endl;
                            }
                            break;
                        case '3':
                            cout << "Input index of task you want to remove: ";
                            cin >> number;
                            if (deque.removeTaskByIndex(number)) {
                                cout << "Task removed" << endl;
                            } else {
                                cout << "Task wasn't found" << endl;
                            }
                            break;
                        case '4':
                            cout << "Input text of task you want to remove: ";
                            getchar();
                            getline(cin, task);
                            if (deque.removeTaskByTask(task)) {
                                cout << "Task removed" << endl;
                            } else {
                                cout << "Task wasn't found" << endl;
                            }
                            break;
                        case '5':
                            cout << "Input priority of task you want to remove: ";
                            cin >> number;
                            if (deque.removeTaskByPriority(number)) {
                                cout << "Task removed" << endl;
                            } else {
                                cout << "Task wasn't found" << endl;
                            }
                            break;
                        case '0':
                            cout << "Returning to main menu" << endl;
                            break;
                        default:
                            cout << "Input error" << endl;
                    }
                    break;
                case 5:
                    printReviewMenu();
                    cin >> input;
                    switch (input) {
                        case '1':
                            if (!deque.isEmpty()) {
                                deque.getFrontTask()->printTask();
                            } else {
                                cout << "Queue is empty" << endl;
                            }
                            break;
                        case '2':
                            if (!deque.isEmpty()) {
                                deque.getTailTask()->printTask();
                            } else {
                                cout << "Queue is empty" << endl;
                            }
                            break;
                        case '3':
                            if (!deque.isEmpty()) {
                                deque.printAllTasks();
                            } else {
                                cout << "Queue is empty" << endl;
                            }
                            break;
                        case '0':
                            cout << "Returning to main menu" << endl;
                            break;
                        default:
                            cout << "Input error" << endl;
                    }
                    break;
                case 6:
                    cout << "Size: " << deque.getSize() << endl;
                case 0:
                    cout << "Exiting..." << endl;
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (choice != 0);
    return 0;
}
