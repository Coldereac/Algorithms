//
// Created by malinka on 20.11.24.
//

#include "functions.h"

#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>

using namespace std;

Node::Node(const string &task, int priority, int index): task(task), next(nullptr), prev(nullptr), priority(priority),
                                                         index(index) {
}

void Node::printTask() const {
    cout << "Index: " << index << ", Priority: " << priority << ", Task " << " : " << task << endl;
}

Deque::Deque(): head(nullptr), tail(nullptr), size(0), indexes(1) {
}

Deque::~Deque() {
    while (head != nullptr) {
        //проходимось починаючи з head і до кінця списку і вивільняємо кожен Node
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

bool Deque::isEmpty() const {
    return head == nullptr || tail == nullptr;
}

int Deque::getSize() const {
    return size;
}

bool Deque::checkTaskForRepeat(const string &task) const {
    for (Node *node = head; node != nullptr; node = node->next) {
        if (node->task == task) {
            return true;
        }
    }
    return false;
}


void Deque::addNormalTask(const string &task) {
    if (checkTaskForRepeat(task)) {
        throw runtime_error("Task already exists");
    }
    auto newNode = new Node(task, size, indexes++);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void Deque::addImportantTask(const string &task) {
    if (checkTaskForRepeat(task)) {
        throw runtime_error("Task already exists");
    }
    auto newNode = new Node(task, 0, indexes++);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        updatePriorities();
    }
    size++;
}

Node *Deque::findByPriority(int priority) const {
    for (Node *temp = head; temp != nullptr; temp = temp->next) {
        if (temp->priority == priority) {
            return temp;
        }
    }
    return nullptr;
}

bool Deque::removeTaskByPriority(int priority) {
    if (priority < 0 || priority > size) {
        throw out_of_range("Priority out of range");
    }
    if (priority == size) {
        return removeBack();
    }
    if (priority == 0) {
        return removeFront();
    }
    Node *found = findByPriority(priority);
    if (found == nullptr) {
        return false;
    }
    Node *temp = found;
    found->prev->next = found->next;
    found->next->prev = found->prev;
    delete temp;
    size--;
    updatePriorities();
    return true;
}

Node *Deque::findByIndex(int index) const {
    for (Node *temp = head; temp != nullptr; temp = temp->next) {
        if (temp->index == index) {
            return temp;
        }
    }
    return nullptr;
}

Node *Deque::findByTask(const string &task) const {
    for (Node *temp = head; temp != nullptr; temp = temp->next) {
        if (temp->task == task) {
            return temp;
        }
    }
    return nullptr;
}


bool Deque::removeTaskByIndex(int index) {
    if (index < 0 || index >= indexes) {
        throw out_of_range("Priority out of range");
    }
    Node *found = findByIndex(index);
    if (found == nullptr) {
        return false;
    }
    Node *temp = found;
    found->prev->next = found->next;
    found->next->prev = found->prev;
    delete temp;
    size--;
    updatePriorities();
    return true;
}

bool Deque::removeTaskByTask(const string &task) {
    if (task.empty()) {
        throw invalid_argument("Task is empty");
    }
    Node *found = findByTask(task);
    if (found == nullptr) {
        return false;
    }
    Node *temp = found;
    found->prev->next = found->next;
    found->next->prev = found->prev;
    delete temp;
    size--;
    updatePriorities();
    return true;
}


void Deque::loadFromFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("File could not be opened");
    }
    string line;
    int maxIndex = 1;
    while (getline(file, line)) {
        stringstream ss(line);
        int index;
        string task;

        // Читаємо індекс і завдання з поточного рядка
        ss >> index;
        if (index > maxIndex) {
            maxIndex = index;
        }
        getline(ss, task);

        // Видалення зайвих пробілів на початку завдання
        task = task.substr(task.find_first_not_of(' '));

        auto newNode = new Node(task, size, index);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    indexes = maxIndex + 1;
    file.close();
}


void Deque::saveToFile(const string &filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("File" + filename + " could not be opened");
    }
    for (Node *node = head; node != nullptr; node = node->next) {
        file << node->index << " " << node->task << endl;
    }
    file.close();
}

bool Deque::removeFront() {
    if (isEmpty()) {
        return false;
    }
    Node *temp = head;
    if (head->next != nullptr) {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    size--;
    updatePriorities();
    return true;
}

bool Deque::removeBack() {
    if (isEmpty()) {
        return false;
    }
    Node *temp = tail;
    if (tail->prev != nullptr) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size--;
    return true;
}

Node *Deque::getFrontTask() const {
    if (isEmpty()) {
        throw runtime_error("Empty Deque");
    }
    return head;
}

Node *Deque::getTailTask() const {
    if (isEmpty()) {
        throw runtime_error("Empty Deque");
    }
    return tail;
}

void Deque::moveFirstToTail() {
    if (isEmpty()) {
        throw runtime_error("Deque is empty");
    }
    Node *temp = head; //збереження голови
    head = head->next; // зсув місця голови на один вперед
    head->prev = nullptr;
    temp->prev = tail; // додаємо збережену голову на початок списку
    tail->next = temp;
    tail = temp;
    tail->next = nullptr;
    updatePriorities();
}

void Deque::printAllTasks() const {
    if (isEmpty()) {
        throw runtime_error("Deque is empty");
    }
    for (Node *node = head; node != nullptr; node = node->next) {
        node->printTask();
    }
}

void Deque::moveLastToFront() {
    if (isEmpty()) {
        throw runtime_error("Deque is empty");
    }
    Node *temp = tail; //збереження хвоста
    tail = tail->prev; // зсув місця хвоста на один назад
    tail->next = nullptr;
    temp->next = head; // додаємо збережений хвіст на початок списку
    head->prev = temp;
    head = temp;
    head->prev = nullptr;
    updatePriorities();
}

void Deque::updatePriorities() const {
    int priority = 0;
    for (Node *node = head; node != nullptr; node = node->next) {
        node->priority = priority++;
    }
}
