/**
 * @file towerOfHanoi.cpp
 * @author Gabe de la Cruz
 * @brief  Program solves the Tower of Hanoi problem.
 * @version 0.1
 * @date 2020-09-28
 * 
 */
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char fromRod, char toRod, char extraRod);

int main()
{
    towerOfHanoi(7, 'A', 'C', 'B');

    return 0;
}

/**
 * @brief This function prints out the steps to solve the
 *        Tower of Hanoi problem. This is implemented as
 *        a recursive function that moves disks from the initial
 *        peg *fromRod* to the destination peg *toRod*
 *        where there is one extra peg *extraRod*.
 * 
 * @param n          number of disks in the initial peg
 * @param fromRod   initial peg
 * @param toRod     destination/target peg
 * @param extraRod  extra peg
 */
void towerOfHanoi(int n, char fromRod, char toRod, char extraRod)
{
    if (n == 1)
    {
        cout << "Move Disk " << n 
             << " from peg " << fromRod 
             << " to peg " << toRod << '\n';
    }
    else
    {
        towerOfHanoi(n - 1, fromRod, extraRod, toRod);
        cout << "Move Disk " << n 
             << " from peg " << fromRod 
             << " to peg " << toRod << '\n';
        towerOfHanoi(n - 1, extraRod, toRod, fromRod);
    }
}