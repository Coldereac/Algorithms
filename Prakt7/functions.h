//
// Created by malinka on 22.10.24.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <vector>

using namespace std;

struct student {
    string name;
    float grade;

    student(string &n, float s) : name(n), grade(s) {
    }
};

struct tree {
    struct student student;
    tree *left;
    tree *right;

    tree(const struct student &_student) : student(_student), left(nullptr), right(nullptr) {
    }
};

tree *insertStudent(tree **t, const student &student);

tree *deleteStudent(tree **t, student &toDelete);

tree *findMin(tree *t);

// якщо дерево пусте return 1, інакше 0
int findStudentsLessGrade(tree *t, float grade, vector<student> &result);

tree *formTree();

void freeTree(tree **t);

int displaySymmetrical(tree *t);

// якщо студент nullptr return 1, інакше 0
int displayStudent(student *student);


#endif //FUNCTIONS_H
