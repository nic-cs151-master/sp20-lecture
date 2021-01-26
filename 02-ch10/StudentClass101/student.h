/**
 * @file student.h
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief Student Class Definition
 * @version 0.1
 * @date 2021-01-20
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

class Student
{
public:
    Student(); // default constructor
    ~Student(); // destructor

    // all member functions that doesn't modify any of the member variables 
    // should be a constant function

    // getters
    string getName() const;
    int getId() const;
    int getAge() const;

    // setters
    void set(string name, int id, int age);
    void setName(string name);
    void setId(int id);
    void setAge(int age);

private:
    string mName;
    int mId;
    int mAge;
};

void displayStudents(Student array[], int size);

#endif