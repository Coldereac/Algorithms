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
    student student(name, grade);
    deleteStudent(&root, student);
    displaySymmetrical(root);
    cout << "Enter grade to find student with grade less than inputed: " << endl;
    cin >> grade;
    vector<struct student> studentLessGrade;
    findStudentsLessGrade(root, grade, studentLessGrade);
    int size = studentLessGrade.size();
    for (int i = 0; i < size; i++) {
        displayStudent(&studentLessGrade[i]);
    }
    freeTree(&root);
    return 0;
}
