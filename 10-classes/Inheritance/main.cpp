#include <iostream>
#include "person.h"
#include "faculty.h"
#include "tfaculty.h"
#include "student.h"
using namespace std;

int main()
{
    TFaculty *prof = new TFaculty("Xavier", COMPUTER_SCIENCE, "Prof.");
    prof->setAge(45);

    cout << "Name of professor: " << prof->getName() << '\n';
    cout << "Age of professor: " << prof->getAge() << '\n';
    cout << "Department: " << prof->getDepartment() << '\n';

    Student st1("Henry", 18, COMPUTER_SCIENCE, prof);

    return 0;
}