//
// Created by malinka on 22.10.24.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    float grade;

    Student(string &n, float s) : name(n), grade(s) {
    }
};

struct tree {
    struct Student student;
    tree *left;
    tree *right;

    tree(const struct Student &_student) : student(_student), left(nullptr), right(nullptr) {
    }
};

tree *insertStudent(tree **t, const Student &student);

tree *deleteStudent(tree **t, Student &toDelete);

tree *findMin(tree *t);

// якщо дерево пусте return 1, інакше 0
int findStudentsLessGrade(tree *t, float grade, tree **result);

tree *formTree();

void freeTree(tree **t);

int displaySymmetrical(tree *t);

// якщо студент nullptr return 1, інакше 0
int displayStudent(Student *student);


#endif //FUNCTIONS_H
