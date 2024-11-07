#include <iostream>
#include "Schedule.h"
using namespace std;

void showMenu() {
    cout << "\n===== Train Schedule Management System =====\n";
    cout << "1. Load train data from file\n";
    cout << "2. Save train data to file\n";
    cout << "3. Display schedule\n";
    cout << "4. Display train by number\n";
    cout << "5. Display all trains to destination\n";
    cout << "6. Add a new train\n";
    cout << "7. Remove a train by number\n";
    cout << "8. Exit\n";
    cout << "===========================================\n";
    cout << "Choose an option: ";
}

int main() {
    Schedule schedule;
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        cin >> choice;

        try {
            if (cin.fail()) {
                throw invalid_argument("Invalid input. Please enter a number.");
            }

            switch (choice) {
                case 1: {
                    char choiceInside;
                    cout << "Do you want to load from standard file?[y/n]";
                    cin >> choiceInside;
                    if (choiceInside == 'y') {
                        schedule.loadFromFile(STANDARDFILE);
                        cout << "Data loaded successfully" << endl;
                    } else {
                        string filename;
                        cout << "Enter filename to load data from: ";
                        cin >> filename;
                        schedule.loadFromFile(filename);
                        cout << "Data loaded successfully from " << filename << ".\n";
                    }
                    break;
                }
                case 2: {
                    string filename;
                    cout << "Enter filename to save data to: ";
                    cin >> filename;
                    schedule.saveToFile(filename);
                    cout << "Data saved successfully to " << filename << ".\n";
                    break;
                }
                case 3: {
                    cout << "\nAll Trains:\n";
                    schedule.displayAll();
                    break;
                }
                case 4: {
                    int trainNumber;
                    cout << "Enter train number: ";
                    cin >> trainNumber;
                    cout << "\nTrain details:\n";
                    schedule.displayTrainByNumber(trainNumber);
                    break;
                }
                // case 5: {
                //     string destination;
                //     cout << "Enter destination: ";
                //     cin >> destination;
                //     cout << "\nTrains to " << destination << ":\n";
                //     schedule.displayByDestination(destination);
                //     break;
                // }
                case 6: {
                    int trainNumber;
                    string destination;
                    int departureHours, departureMinutes;
                    cout << "Enter train number: ";
                    cin >> trainNumber;
                    cout << "Enter destination: ";
                    cin >> destination;
                    cout << "Enter departure time (HH MM): ";
                    cin >> departureHours >> departureMinutes;
                    Train train(trainNumber, destination, departureHours, departureMinutes);
                    schedule.insert(train);
                    cout << "Train added successfully.\n";
                    break;
                }
                case 7: {
                    int trainNumber;
                    cout << "Enter train number to remove: ";
                    cin >> trainNumber;
                    schedule.remove(trainNumber);
                    cout << "Train removed successfully (if it existed).\n";
                    break;
                }
                case 8: {
                    running = false;
                    cout << "Exiting program.\n";
                    break;
                }
                default:
                    cout << "Invalid option. Please try again.\n";
            }
        } catch (const invalid_argument &e) {
            cerr << "Input Error: " << e.what() << endl;
        } catch (const runtime_error &e) {
            cerr << "Runtime Error: " << e.what() << endl;
        } catch (...) {
            cerr << "An unexpected error occurred." << endl;
        }
    }

    return 0;
}
