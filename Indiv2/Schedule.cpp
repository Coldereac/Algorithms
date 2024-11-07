//
// Created by malinka on 07.11.24.
//

#include "Schedule.h"

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
    cout << "Train number: " << number << ", Destination: " << destination
            << ", Departure time: " << departureHours << ":" << departureMinutes << endl;
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

AVLNode* AVLNode::searchByNumber(int number) {
    // Перевіряємо поточний вузол
    if (number == data.number) {
        return this;
    }
    // Рекурсивно шукаємо в лівому піддереві, якщо існує
    AVLNode* foundNode = nullptr;
    if (left != nullptr) {
        foundNode = left->searchByNumber(number);
    }
    // Якщо не знайдено в лівому піддереві, шукаємо в правому піддереві
    if (foundNode == nullptr && right != nullptr) {
        foundNode = right->searchByNumber(number);
    }
    return foundNode;
}


Schedule::Schedule() : root(nullptr) {
}

int compareTime(Train &train1, Train &train2) {
    return (train1.departureHours * 60 + train1.departureMinutes) - (
               train2.departureHours * 60 + train2.departureMinutes);
}

AVLNode *Schedule::insert(AVLNode *node, Train &data) {
    if (!node) return new AVLNode(data);

    if (compareTime(data, node->data) < 0)
        node->left = insert(node->left, data);
    else if (compareTime(data, node->data) > 0)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(node->left->getHeight(), node->right->getHeight());
    int balance = node->getBalance();

    if (balance > 1 && compareTime(data, node->left->data) < 0)
        return node->rotateRight();
    if (balance < -1 && compareTime(data, node->left->data) > 0)
        return node->rotateLeft();
    if (balance > 1 && compareTime(data, node->left->data) > 0) {
        node->left = node->left->rotateLeft();
        return node->rotateRight();
    }
    if (balance < -1 && compareTime(data, node->left->data) < 0) {
        node->right = node->right->rotateRight();
        return node->rotateLeft();
    }

    return node;
}

AVLNode* Schedule::remove(AVLNode *node, Train &train) {
    if (!node) return node;

    // Порівняння за часом відправлення, а не за номером
    int comparison = compareTime(train, node->data);
    if (comparison < 0) {
        node->left = remove(node->left, train);
    } else if (comparison > 0) {
        node->right = remove(node->right, train);
    } else {
        // Вузол знайдено
        if (!node->left || !node->right) {
            AVLNode *temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            AVLNode *temp = node->right->findMin();
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    // Оновлення висоти та балансування дерева
    if (node) {
        node->height = 1 + max(node->left->getHeight(), node->right->getHeight());
        int balance = node->getBalance();

        if (balance > 1 && node->left->getBalance() >= 0)
            return node->rotateRight();
        if (balance > 1 && node->left->getBalance() < 0) {
            node->left = node->left->rotateLeft();
            return node->rotateRight();
        }
        if (balance < -1 && node->right->getBalance() <= 0)
            return node->rotateLeft();
        if (balance < -1 && node->right->getBalance() > 0) {
            node->right = node->right->rotateRight();
            return node->rotateLeft();
        }
    }

    return node;
}


void Schedule::inOrder(const AVLNode *node) {
    if (node) {
        inOrder(node->left);
        node->data.printInfo();
        inOrder(node->right);
    }
}

void Schedule::insert(Train &data) {
    root = insert(root, data);
}

void Schedule::remove(int number) {
    root = remove(root, number);
}

void Schedule::displayAll() const {
    inOrder(root);
}

void Schedule::displayTrainByNumber(int number) const {
    AVLNode *trainNode = root ? root->searchByNumber(number) : nullptr;
    if (trainNode) trainNode->data.printInfo();
    else cout << "Train not found." << endl;
}

void Schedule::saveToFile(const string &filename) const {
    ofstream file(filename);
    if (file.is_open()) {
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

void Schedule::loadFromFile(const string &filename) {
    ifstream file(filename);

    if (file.is_open()) {
        int nodeCount = 0;
        int number;
        string destination;
        int departureHours;
        int departureMinutes;

        while (file >> number >> destination >> departureHours >> departureMinutes) {
            nodeCount++;
        }

        file.clear();
        file.seekg(0, ios::beg);

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
