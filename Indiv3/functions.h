//
// Created by malinka on 20.11.24.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define DATA_STANDARD_PATH "/home/malinka/CLionProjects/Algorithms/cmake-build-debug/Indiv3/data.txt"

using namespace std;
#include <string>

struct Node {
    string task;
    Node *next;
    Node *prev;
    int priority;
    int index;

    Node(const string &task = "", int priority = -1, int index = -1);

    void printTask() const;
};


class Deque {
    Node *head;
    Node *tail;
    int size;
    int indexes;

    void updatePriorities() const;

    bool checkTaskForRepeat(const string &task) const;

public:
    Deque();

    ~Deque();

    void loadFromFile(const string &filename);

    void saveToFile(const string &filename) const;

    void addNormalTask(const string &task);

    void addImportantTask(const string &task);

    Node *findByPriority(int priority) const;

    bool removeTaskByPriority(int priority);

    Node *findByIndex(int index) const;

    Node *findByTask(const string &task) const;

    bool removeTaskByIndex(int index);

    bool removeTaskByTask(const string &task);

    bool removeFront();

    bool removeBack();

    Node *getFrontTask() const;

    Node *getTailTask() const;

    bool isEmpty() const;

    int getSize() const;

    void moveLastToFront();

    void moveFirstToTail();

    void printAllTasks() const;
};


#endif //FUNCTIONS_H
