#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

// enum class
enum Discipline {GEOLOGY, BIOLOGY, COMPUTER_SCIENCE, MATH, PHYSICS};

// parent class
class Person
{
public:
    Person();
    Person(const string &name);
    Person(const string &name, int age);
    virtual ~Person();
    
    void setName(const string &name);
    string getName() const;

    void setAge(int age);
    int getAge() const;

protected:
    string mName;

private:
    // string mName;
    int mAge;
};

#endif