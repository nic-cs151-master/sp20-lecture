/**
 * @file    readCsv.cpp
 * @author  Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief   Previous way of reading data from a file.
 * @version 0.1
 * @date    2021-01-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;

int main()
{
    ifstream csvFile("data.csv");

    if (!csvFile)
    {
        cerr << "Error opening file\n";
        exit(-1);
    }

    // read file header
    string header = "";
    getline(csvFile, header);

    while (!csvFile.eof())
    {
        string name = "";
        getline(csvFile, name, ',');

        int age = 0;
        char delim = '\0';
        csvFile >> age >> delim;

        string address = "";
        getline(csvFile, address, ',');

        long int phone = 0;
        csvFile >> phone;
        csvFile.get(); // read '\n'

        cout << name << ' '
             << age << ' '
             << address << ' '
             << phone << '\n';
    }

    return 0;
}