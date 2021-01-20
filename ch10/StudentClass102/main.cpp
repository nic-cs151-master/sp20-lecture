/**
 * @file main.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief Review on Classes
 * @version 0.1
 * @date 2021-01-20
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
    studentList[0].setName("John");
    studentList[0].setId(6754);
    studentList[0].setAge(23);

    // studentList[1].name = "Carol";
    // studentList[1].id = 2343;
    // studentList[1].age = 18;
    studentList[1].set("Carol", 2343, 18);

    // studentList[2].name = "Cindy";
    // studentList[2].id = 9787;
    // studentList[2].age = 30;
    studentList[2].set("Cindy", 9787, 30);

    // studentList[3].name = "Bob";
    // studentList[3].id = 7898;
    // studentList[3].age = 16;
    studentList[2].set("Bob", 7898, 16);

    displayStudents(studentList, NUM_STUDENTS);

    return 0;
}