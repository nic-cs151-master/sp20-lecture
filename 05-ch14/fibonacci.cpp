/**
 * @file fibonacci.cpp
 * @author Gabe de la Cruz (gvdelacruz@nic.edu)
 * @brief Recursive implementation of the fibonacci series
 * @version 0.1
 * @date 2021-02-10
 * 
 */
#include <iostream>

using std::cout;

int fib(int n);

int main()
{
    return 0;
}

int fib(int n)
{
    if (n <= 0)         // base case
    {
        return 0;
    }
    else if (n == 1)    // base case
    {
        return 1;
    }
    else               // recursive case
    {
        return fib(n - 1) + fib(n - 2);
    }
}