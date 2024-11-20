#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

//  + + / - 30 20 + 95 64 * 86 24 87 ((((30-20)/(95+64))+(86*24))+87)
// * + A B - C D ((A + B) * (C - D))
// + * A B ? C D Invalid element found: ?

struct Node {
    string value;
    Node *left;
    Node *right;

    Node(string val) : value(val), left(nullptr), right(nullptr) {
    }
};

// Функція перевірки коректності елемента
bool validateElement(const string &element) {
    // Дозволені оператори
    if (element == "+" || element == "-" || element == "*" || element == "/") return true;

    // Перевірка, чи елемент є числом
    for (char ch: element) {
        if (!isdigit(ch) && !isalpha(ch)) {
            return false;
        }
    }
    return true;
}

// Функція для побудови дерева з префіксного виразу
Node *buildExpressionTree(istringstream &iss) {
    string current;
    if (!(iss >> current)) return nullptr; // Зчитуємо наступний елемент (оператор або операнд)

    if (!validateElement(current)) {
        throw invalid_argument("Invalid element found: " + current);
    }

    Node *node = new Node(current);

    // Якщо це оператор, будуємо піддерева
    if (current == "+" || current == "-" || current == "*" || current == "/") {
        node->left = buildExpressionTree(iss);
        node->right = buildExpressionTree(iss);
    }
    return node;
}

void printInfix(Node *root) {
    if (root == nullptr) return;

    if (root->left) cout << "(";
    printInfix(root->left);
    cout << root->value;
    printInfix(root->right);
    if (root->right) cout << ")";
}


void deleteTree(Node *root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


int main() {
    string prefix;
    cout << "Input the prefix expression (use spaces to separate elements): ";
    getline(cin, prefix); // Зчитуємо весь рядок

    try {
        istringstream iss(prefix);

        Node *root = buildExpressionTree(iss);

        cout << "Infix expression: ";
        printInfix(root);
        cout << endl;

        deleteTree(root);
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
