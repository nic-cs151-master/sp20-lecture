#include "student.h"

void sortByName(Student array[], int size)
{
    for (int startScan = 1; startScan < size; ++startScan)
    {
        Student key = array[startScan];
        int index = startScan - 1;

        while (index >= 0 && array[index].getName() > key.getName())
        {
            array[index+1] = array[index];
            --index;
        }
        array[index+1] = key;
    }
}

void display(const Student array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << setw(6) << right << array[i].getId()   << ' '
             << setw(8) << left  << array[i].getName() << ' '
             << setw(4) << right << array[i].getAge()  << '\n';
    }
}

// constructors
Student::Student()
{
    mId = 0;    // default value is zero
    mName = ""; // default value is an empty string
    mAge = 0;   // default value is zero
}

Student::Student(int id, string name, int age)
{
    setStudent(id, name, age);
}

// setters or mutators
void Student::setStudent(int id, string name, int age)
{
    mId = id;
    mName = name;
    mAge = age;
}

void Student::setId(int id)
{
    mId = id;
}

void Student::setName(string name)
{
    mName = name;
}

void Student::setAge(int age)
{
    mAge = age;
}

// getters or accessors
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