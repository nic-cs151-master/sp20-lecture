/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include "student.h"
using namespace std;

// global variable
const int NUM_STUDENTS = 4;

int main()
{
    Student studentList[NUM_STUDENTS];

    // 1st: John, 23, 6754
    studentList[0].name = "John";
    studentList[0].id = 6754;
    studentList[0].age = 23;

    studentList[1].name = "Carol";
    studentList[1].id = 2343;
    studentList[1].age = 18;

    studentList[2].name = "Cindy";
    studentList[2].id = 9787;
    studentList[2].age = 30;

    studentList[3].name = "Bob";
    studentList[3].id = 7898;
    studentList[3].age = 16;

    displayStudents(studentList, NUM_STUDENTS);

    return 0;
}