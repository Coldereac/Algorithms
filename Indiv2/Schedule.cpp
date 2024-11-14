//
// Created by malinka on 07.11.24.
//

#include "Schedule.h"

#include <iomanip>

Train::Train(int number, const string &destination, int departureHours, int departureMinutes) {
    if (number <= 0) {
        throw out_of_range("Number must be greater than zero");
    }
    if (destination.empty()) {
        throw invalid_argument("Destination must be not empty");
    }
    if (departureHours < 0) {
        throw out_of_range("Departure hours must be greater than or equals to zero");
    }
    if (departureHours > 23) {
        throw out_of_range("Departure hours must be less than 23");
    }
    if (departureMinutes < 0) {
        throw out_of_range("Departure minutes must be greater than or equals to zero");
    }
    if (departureMinutes > 59) {
        throw out_of_range("Departure minutes must be less than 59");
    }
    this->number = number;
    this->destination = destination;
    this->departureHours = departureHours;
    this->departureMinutes = departureMinutes;
}

void Train::printInfo() const {
    cout << "Train number: " << number << ", Destination: " << setw(20) << setfill(' ') << left << destination
            << ", Departure time: " << right << std::setw(2) << std::setfill('0') << departureHours << ":" <<
            std::setw(2) <<
            std::setfill('0') << departureMinutes << endl;
}

AVLNode::AVLNode(Train &data): data(data), left(nullptr), right(nullptr), height(0) {
}

int AVLNode::getHeight() const {
    return height;
}


int AVLNode::getBalance() const {
    return (left ? left->height : 0) - (right ? right->height : 0);
}

AVLNode *AVLNode::rotateRight() {
    AVLNode *x = left;
    AVLNode *T2 = x->right;

    x->right = this;
    left = T2;

    height = max(left ? left->height : 0, right ? right->height : 0) + 1;
    x->height = max(x->left ? x->left->height : 0, height) + 1;

    return x;
}

AVLNode *AVLNode::rotateLeft() {
    AVLNode *y = right;
    AVLNode *T2 = y->left;

    y->left = this;
    right = T2;

    height = max(left ? left->height : 0, right ? right->height : 0) + 1;
    y->height = max(y->right ? y->right->height : 0, height) + 1;

    return y;
}

AVLNode *AVLNode::findMin() {
    AVLNode *current = this;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

AVLNode *Schedule::searchByNumber(int number, AVLNode *node) {
    if (!node || node->data.number == number)
        return node;
    if (number < node->data.number)
        return searchByNumber(number, node->left);
    return searchByNumber(number, node->right);
}

Schedule *Schedule::searchByDestination(const string &destination) const {
    auto *result = new Schedule();
    searchByDestinationHelper(root, destination, result);
    return result;
}

void Schedule::searchByDestinationHelper(AVLNode *node, const string &destination, Schedule *result) {
    if (!node) return;

    // Рекурсивний обхід лівого піддерева
    searchByDestinationHelper(node->left, destination, result);

    // Перевірка, чи відповідає поточний поїзд призначенню
    if (node->data.destination == destination) {
        result->insert(node->data); // Додавання у нове дерево результатів
    }

    // Рекурсивний обхід правого піддерева
    searchByDestinationHelper(node->right, destination, result);
}


Schedule::Schedule() : root(nullptr) {
}

AVLNode *Schedule::insert(AVLNode *node, Train &data) {
    if (!node) return new AVLNode(data);

    // Перевірка дубліката за номером поїзда
    if (data.number == node->data.number) {
        throw std::runtime_error("Train with number " + std::to_string(data.number) + " already exists.");
    }

    if (data.number < node->data.number)
        node->left = insert(node->left, data);
    else if (data.number > node->data.number)
        node->right = insert(node->right, data);

    node->height = 1 + max(node->left ? node->left->getHeight() : 0, node->right ? node->right->getHeight() : 0);
    int balance = node->getBalance();

    if (balance > 1 && node->left && data.number < node->left->data.number) {
        return node->rotateRight();
    }

    if (balance < -1 && node->right && data.number > node->right->data.number) {
        return node->rotateLeft();
    }

    if (balance > 1 && node->left && data.number > node->left->data.number) {
        node->left = node->left->rotateLeft();
        return node->rotateRight();
    }

    if (balance < -1 && node->right && data.number < node->right->data.number) {
        node->right = node->right->rotateRight();
        return node->rotateLeft();
    }

    return node;
}

AVLNode *Schedule::remove(AVLNode *node, int number) {
    // Базовий випадок: якщо вузол порожній, поїзд не знайдено
    if (!node) {
        throw std::runtime_error("Train with number " + std::to_string(number) + " not found.");
    }

    // Пошук вузла для видалення
    if (number < node->data.number) {
        node->left = remove(node->left, number);
    } else if (number > node->data.number) {
        node->right = remove(node->right, number);
    } else {
        // Номер збігається, вузол знайдено та готується до видалення

        // Вузол з одним або без дочірніх вузлів
        if (!node->left || !node->right) {
            AVLNode *temp = node->left ? node->left : node->right;
            delete node; // видаляємо поточний вузол
            return temp;
        } else {
            // Вузол з двома дочірніми елементами
            AVLNode *minNode = node->right->findMin();
            node->data = minNode->data;
            node->right = remove(node->right, minNode->data.number);
        }
    }

    // Оновлення висоти поточного вузла
    node->height = 1 + max(
                       node->left ? node->left->height : 0,
                       node->right ? node->right->height : 0
                   );

    // Балансування дерева
    int balance = node->getBalance();

    // Чотири випадки дисбалансу
    // Case 1: Left Left
    if (balance > 1 && node->left && node->left->getBalance() >= 0) {
        return node->rotateRight();
    }

    // Case 2: Left Right
    if (balance > 1 && node->left && node->left->getBalance() < 0) {
        node->left = node->left->rotateLeft();
        return node->rotateRight();
    }

    // Case 3: Right Right
    if (balance < -1 && node->right && node->right->getBalance() <= 0) {
        return node->rotateLeft();
    }

    // Case 4: Right Left
    if (balance < -1 && node->right && node->right->getBalance() > 0) {
        node->right = node->right->rotateRight();
        return node->rotateLeft();
    }

    return node;
}

void Schedule::destroyTree(AVLNode *node) {
    if (!node) return;

    // Спершу звільняємо ліве і праве піддерева
    destroyTree(node->left);
    destroyTree(node->right);

    // Звільняємо поточний вузол
    delete node;
}

Schedule::~Schedule() {
    destroyTree(root);
    root = nullptr;
}


void Schedule::displayAllHelper(const AVLNode *node) {
    if (node) {
        displayAllHelper(node->left);
        node->data.printInfo();
        displayAllHelper(node->right);
    }
}

void Schedule::insert(Train &data) {
    root = insert(root, data);
}

void Schedule::remove(int number) {
    root = remove(root, number);
}

void Schedule::displayAll() const {
    displayAllHelper(root);
}

void Schedule::displayTrainByNumber(int number) const {
    if (AVLNode *trainNode = root ? searchByNumber(number, root) : nullptr) trainNode->data.printInfo();
    else cout << "Train not found." << endl;
}

void Schedule::saveToFile(const string &filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        file << countNodes(root) << endl;
        saveToFile(root, file);
        file.close();
    }
}

void Schedule::saveToFile(const AVLNode *node, ofstream &file) {
    if (node) {
        saveToFile(node->left, file);
        file << node->data.number << " " << node->data.destination
                << " " << node->data.departureHours << " " << node->data.departureMinutes << endl;
        saveToFile(node->right, file);
    }
}

int Schedule::countNodes(AVLNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

void Schedule::loadFromFile(const string &filename) {
    ifstream file(filename);

    if (file.is_open()) {
        int nodeCount;
        file >> nodeCount;

        root = buildBalancedTreeFromFile(file, 0, nodeCount - 1);
        file.close();
    }
}

AVLNode *Schedule::buildBalancedTreeFromFile(ifstream &file, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;

    AVLNode *leftChild = buildBalancedTreeFromFile(file, start, mid - 1);

    int number;
    string destination;
    int departureHours;
    int departureMinutes;
    file >> number >> destination >> departureHours >> departureMinutes;
    Train train = Train(number, destination, departureHours, departureMinutes);
    auto *node = new AVLNode(train);

    node->left = leftChild;

    node->right = buildBalancedTreeFromFile(file, mid + 1, end);

    node->height = 1 + max(node->left ? node->left->getHeight() : 0,
                           node->right ? node->right->getHeight() : 0);

    return node;
}
