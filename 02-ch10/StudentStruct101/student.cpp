/**
 * @file student.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief 
 * @version 0.1
 * @date 2021-01-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "student.h"

/**
 * @brief 
 * 
 * @param array 
 * @param size 
 */
void displayStudents(Student array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i].name << ' ' 
             << array[i].id << ' ' 
             << array[i].age << '\n';
    }
}