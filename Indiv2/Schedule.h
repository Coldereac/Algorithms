//
// Created by malinka on 07.11.24.
//

#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#define STANDARDFILE "/home/malinka/CLionProjects/Algorithms/cmake-build-debug/Indiv2/data.txt"

class Train {
public:
    int number;
    string destination;
    int departureMinutes;
    int departureHours;

    Train(int number = 1, const string &destination = "", int departureHours = 0, int departureMinutes = 0);

    void printInfo() const;
};

class AVLNode {
public:
    Train data;
    AVLNode *left;
    AVLNode *right;
    int height;

    explicit AVLNode(Train &data);

    [[nodiscard]] int getHeight() const;

    [[nodiscard]] int getBalance() const;

    AVLNode *rotateRight();

    AVLNode *rotateLeft();

    AVLNode *findMin();
};


class Schedule {
    AVLNode *root;

    static void saveToFile(const AVLNode *node, ofstream &file);

    static AVLNode *buildBalancedTreeFromFile(ifstream &file, int start, int end);

    static int countNodes(AVLNode* node);

public:
    Schedule();

    void insert(Train &data);

    void remove(int number);

    void displayAll() const;

    void displayTrainByNumber(int number) const;

    void saveToFile(const string &filename) const;

    void loadFromFile(const string &filename);

    Schedule *searchByDestination(const string &destination) const;

    void searchByDestinationHelper(AVLNode *node, const string &destination, Schedule *result) const;

    static AVLNode *searchByNumber(int number, AVLNode *node);

    static void printInOrder(const AVLNode *node);

    static AVLNode *insert(AVLNode *node, Train &data);

    static AVLNode *remove(AVLNode *node, int number);

    void destroyTree(AVLNode *node);

    ~Schedule();
};


#endif //SCHEDULE_H
