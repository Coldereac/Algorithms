//
// Created by malinka on 22.10.24.
//
#include <iostream>

#include "functions.h"

int main() {
    cout << "Forming a tree. Enter first student:\n";
    tree *root = formTree();
    displaySymmetrical(root);
    string name;
    float grade;
    cout << "Enter student to delete: ";
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student grade: ";
    cin >> grade;
    Student student(name, grade);
    deleteStudent(&root, student);
    displaySymmetrical(root);
    cout << "Enter grade to find student with grade less than inputed: " << endl;
    cin >> grade;
    tree *studentLessGrade = nullptr;
    findStudentsLessGrade(root, grade, &studentLessGrade);
    displaySymmetrical(studentLessGrade);
    freeTree(&root);
    return 0;
}
