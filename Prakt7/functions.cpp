//
// Created by malinka on 22.10.24.
//

#include "functions.h"

#include <iostream>

tree *insertStudent(tree **t, const Student &student) {
    if (*t == nullptr) {
        *t = new tree(student);
        return *t;
    }
    if ((*t)->student.grade < student.grade) {
        (*t)->left = insertStudent(&(*t)->left, student);
    } else {
        (*t)->right = insertStudent(&(*t)->right, student);
    }
    return *t;
};

tree *formTree() {
    tree *t = nullptr;
    char choice;
    do {
        string name;
        float grade;
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student grade: ";
        cin >> grade;
        insertStudent(&t, Student(name, grade));
        cout << "Do you want to add another element to the tree [Yy\\Nn]: ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    return t;
}

tree *deleteStudent(tree **t, Student &toDelete) {
    if (*t == nullptr) {
        return nullptr;
    }
    if ((*t)->student.grade < toDelete.grade) {
        (*t)->left = deleteStudent(&(*t)->left, toDelete);
    } else if ((*t)->student.grade > toDelete.grade) {
        (*t)->right = deleteStudent(&(*t)->right, toDelete);
    } else if ((*t)->student.name == toDelete.name) {
        if ((*t)->left == nullptr && (*t)->right == nullptr) {
            delete *t;
            return nullptr;
        }
        if ((*t)->left == nullptr) {
            tree *temp = (*t)->right;
            delete *t;
            return temp;
        }
        if ((*t)->right == nullptr) {
            tree *temp = (*t)->left;
            delete *t;
            return temp;
        }
        // Замінити на мінімальне значення в правому піддереві
        tree *temp = findMin((*t)->right);
        (*t)->student.name = temp->student.name;
        (*t)->student.grade = temp->student.grade;
        (*t)->right = deleteStudent(&(*t)->right, temp->student);
    }

    return *t;
}

tree *findMin(tree *t) {
    while (t->left != nullptr) {
        t = t->left;
    }
    return t;
}

int findStudentsLessGrade(tree *t, float grade, tree **result) {
    if (t == nullptr) {
        return 1;
    }
    findStudentsLessGrade(t->left, grade, result);
    if (grade > t->student.grade) {
        insertStudent(result, t->student);
    }
    findStudentsLessGrade(t->right, grade, result);

    return 0;
}

void freeTree(tree **t) {
    if (*t == nullptr) {
        return;
    }
    freeTree(&(*t)->left);
    freeTree(&(*t)->right);
    delete *t;
}

int displayStudent(Student *student) {
    if (student == nullptr) return 1;
    cout << "Name: " << student->name << "\nGrade: " << student->grade << endl;
    return 0;
}

int displaySymmetrical(tree *t) {
    if (t == nullptr) return 1;
    displaySymmetrical(t->left);
    displayStudent(&t->student);
    displaySymmetrical(t->right);
    return 0;
}
