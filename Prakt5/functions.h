//
// Created by Malinka on 10/3/2024.
//

#ifndef ALGORITHMS_FUNCTIONS_H
#define ALGORITHMS_FUNCTIONS_H

struct Node {
    int data;
    Node *next;
    Node *prev;
};

typedef Node *PNode;

PNode createList();

void printForward(PNode head);

void printBackward(PNode tail);

void deleteNode(PNode *head, int value);

void insertBefore(PNode *head, int beforeValue, int newValue);

void insertAfter(PNode head, int afterValue, int newValue);

bool isSymmetric(PNode head);

void menu();

void freeMemory(PNode *node);

#endif //ALGORITHMS_FUNCTIONS_H
