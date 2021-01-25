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

// global
const int NUM_SUDENTS = 3;

int main()
{
    Student studentList[NUM_SUDENTS];

    // John, 1001, 21
    studentList[0].setName("John");
    studentList[0].setId(1001);
    studentList[0].setAge(21);

    // studentList[1].name = "Jane";
    // studentList[1].id = 982;
    // studentList[1].age = 30;
    studentList[1].set("Jane", 982, 30);

    // studentList[2].name = "Cindy";
    // studentList[2].id = 456;
    // studentList[2].age = 18;
    studentList[2].set("Cindy", 456, 18);

    displayStudents(studentList, NUM_SUDENTS);

    return 0;
}