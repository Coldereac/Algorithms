#include <iostream>

#include "header.h"
using namespace std;

pnode formLIFO_1() {
    int info;
    pnode top = NULL, cur;
    cin >> info;
    while (info) {
        cur = new tnode;
        cur->info = info;
        cur->next = top;
        top = cur;
        cin >> info;
    }
    return top;
}

void formLIFO_2(pnode *top) {
    int info;
    pnode cur;
    *top = NULL;
    cin >> info;
    while (info) {
        cur = new tnode;
        cur->info = info;
        cur->next = *top;
        *top = cur;
        cin >> info;
    }
}

void display(pnode node) {
    pnode cur = node;
    while (cur != NULL) {
        printf("%d ", cur->info);
        cur = cur->next;
    }
    printf("\n");
}
