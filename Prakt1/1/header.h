//
// Created by malinka on 18.09.24.
//

#ifndef HEADER_H
#define HEADER_H

struct tnode {
    int info;
    tnode *next;
};

typedef tnode *pnode;


pnode formLIFO_1();

void formLIFO_2(pnode *top);

void display(const pnode node);

#endif //HEADER_H
