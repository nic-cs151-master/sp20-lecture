/**
 * @file student.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief Student Class Implementation
 * @version 0.1
 * @date 2021-01-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "student.h"

Student::Student()
{
    // default values
    mId = 111111;
    mName = ""; // empty string
    mAge = 0;
}

Student::~Student()
{
    // no use for now
}

int Student::getId() const
{
    return mId;
}

string Student::getName() const
{
    return mName;
}

int Student::getAge() const
{
    return mAge;
}

void Student::set(string name, int id, int age)
{
    setId(id);
    setName(name);
    setAge(age);
}

// setters
void Student::setId(int id)
{
    if (id < 0 || id > 999999)
    {
        cout << "Invalid id value\n";
        return;
    }
    mId = id;
}

void Student::setName(string name)
{
    if (name == "Dahlia")
    {
        cout << "Cannot accep this name";
        return;
    }
    mName = name;
}

void Student::setAge(int age)
{
    mAge = age;
}

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
        cout << array[i].getName() << ' ' 
             << array[i].getId() << ' ' 
             << array[i].getAge() << '\n';
    }
}