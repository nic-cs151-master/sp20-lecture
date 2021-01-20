/**
 * @file student.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "student.h"

/**
 * @brief 
 * 
 * @param arr 
 * @param size 
 */
void displayStudents(const Student arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i].name << ' ' 
             << arr[i].id << ' ' 
             << arr[i].age << '\n';
    }
}