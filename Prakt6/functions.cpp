//
// Created by malinka on 22.10.24.
//

#include "functions.h"

#include <iostream>
using namespace std;

tree *formTree() {
    tree *t;
    int data;
    cin >> data;
    if (data == 0)
        return nullptr;
    t = new tree;
    t->data = data;
    t->left = formTree();
    t->right = formTree();
    return t;
}

int displayStraight(tree *t) {
    if (t == nullptr) return 1;
    cout << t->data << endl;
    displayStraight(t->left);
    displayStraight(t->right);
    return 0;
}

int displaySymmetrical(tree *t) {
    if (t == nullptr) return 1;
    displaySymmetrical(t->left);
    cout << t->data << endl;
    displaySymmetrical(t->right);
    return 0;
}

int displayReverse(tree *t) {
    if (t == nullptr) return 1;
    displayReverse(t->left);
    displayReverse(t->right);
    cout << t->data << endl;
    return 0;
}

int countElem(tree *t, int elem) {
    if (t == nullptr) return 0;
    if (elem == 0) return -1;
    int count = (t->data == elem) ? 1 : 0;
    count += countElem(t->left, elem);
    count += countElem(t->right, elem);
    return count;
}
