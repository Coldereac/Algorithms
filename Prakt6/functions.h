//
// Created by malinka on 22.10.24.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

tree *formTree();

int displayStraight(tree *t);

int displaySymmetrical(tree *t);

int displayReverse(tree *t);

int countElem(tree *t, int elem);

#endif //FUNCTIONS_H
