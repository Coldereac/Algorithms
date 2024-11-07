//
// Created by malinka on 22.10.24.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*
*1. Напишіть функцію для створення довільного бінарного дерева за
даними, введеними з клавіатури.
2. Напишіть функції обходу бінарного дерева в прямому,
симетричному та зворотному порядках.
3. Напишіть функцію, яка повертає кількість елементів дерева, що
дорівнюють значенню, заданому в параметрі функції.
 */

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

tree *formTree();

//if tree is null return 1, else 0;
int displayStraight(tree *t);

//if tree is null return 1, else 0;
int displaySymmetrical(tree *t);

//if tree is null return 1, else 0;
int displayReverse(tree *t);

//if tree is null return 1, if elem to count is 0 return -1, else 0;
int countElem(tree *t, int elem);

#endif //FUNCTIONS_H
