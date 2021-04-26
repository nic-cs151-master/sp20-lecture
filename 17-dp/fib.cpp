#include <iostream>
#include <unordered_map>
#include "stopwatch.h"

using std::cout;
using std::unordered_map;

int fib(int n);
int fib2(int n, unordered_map<int,int> &results);

int main()
{
    int number = 40; // 11 vs 40
    StopWatch t; // starts the clock

    cout << fib(number) << '\n';

    cout << t.restartClock()
         << " microseconds" << std::endl;

    unordered_map<int, int> table;
    cout << fib2(number, table) << '\n';

    cout << t.restartClock()
         << " microseconds" << std::endl;

    return 0;
}

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1; 
    else 
        return fib(n - 1) + fib(n - 2);
}

int fib2(int n, unordered_map<int,int> &results)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1; 
    else if (results.find(n) != results.end())
        return results[n];
    else
        return results[n] = fib2(n - 1, results) + fib2(n - 2, results);
}