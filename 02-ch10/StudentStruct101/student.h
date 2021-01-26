/**
 * @file student.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
// Guard code
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

struct Student
{
    string name;
    int id;
    int age;
};

void displayStudents(Student array[], int size);

#endif