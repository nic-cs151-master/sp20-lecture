/**
 * @file    readCsv_v2.cpp
 * @author  Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief   Better way of reading data from a file
 *          using string stream and getline
 * @version 0.2
 * @date    2021-01-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;
using std::istringstream;

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

    string line = "";
    while (getline(csvFile, line))
    {
        istringstream istr(line);

        string name = "";
        getline(istr, name, ',');

        int age = 0;
        char delim = '\0';
        istr >> age >> delim;

        string address = "";
        getline(istr, address, ',');

        long int phone = 0;
        istr >> phone;
        // csvFile.get(); // read '\n'

        cout << name << ' '
             << age << ' '
             << address << ' '
             << phone << '\n';
    }

    return 0;
}