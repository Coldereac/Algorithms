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
    int departureHours;
    int departureMinutes;

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

    AVLNode *searchByNumber(int number);

};


class Schedule {
    AVLNode *root;

    static AVLNode *insert(AVLNode *node, Train &data);

    static AVLNode *remove(AVLNode *node, int number);

    static void inOrder(const AVLNode *node);

    static void saveToFile(const AVLNode *node, ofstream &file);

    static AVLNode *buildBalancedTreeFromFile(ifstream &file, int start, int end);

public:
    Schedule();
    void insert(Train &data);
    void remove(int number);
    void displayAll() const;
    void displayTrainByNumber(int number) const;
    void saveToFile(const string &filename) const;
    void loadFromFile(const string &filename);
};


#endif //SCHEDULE_H
