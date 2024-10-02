#ifndef ALGORITHMS_FUNCTIONS_H
#define ALGORITHMS_FUNCTIONS_H

struct Node {
    int data;
    Node* next;
};

typedef Node *PNode;

void printList(PNode head);

void deleteNode(PNode *head, int value);

void createOrderedList(PNode *head, int size);

void insertOrdered(PNode *head, int value);

#endif