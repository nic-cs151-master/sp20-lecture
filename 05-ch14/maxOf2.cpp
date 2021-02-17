#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::max;

int maxOf(const vector<int> &numbers);
int maxOf2(const vector<int> &numbers);
vector<int> subList(const vector<int> &v, int m, int n);

int main()
{
    vector<int> elems{137, 271, 828, 182, 200, 983, 1023, 33, 12, 103};
    cout << maxOf(elems) << '\n'; // 1023
    cout << maxOf2(elems) << '\n'; // 1023
    return 0;
}

int maxOf(const vector<int> &numbers)
{
    // base case
    if (numbers.size() == 1)
    {
        return numbers[0];
    }
    else
    {
        // recursive case
        int first = numbers[0];
        // get the remaining list exluding the first element
        vector<int> remaining = subList(numbers, 1, numbers.size() - 1);
        return max(first, maxOf(remaining));
    }
}

int maxOf2(const vector<int> &numbers)
{
    // base case
    if (numbers.size() == 1)
    {
        return numbers[0];
    }
    else
    {
        // recursive case
        // get the remaining list exluding the first element
        int mid = numbers.size() / 2;
        vector<int> upper = subList(numbers, 0, mid - 1);
        vector<int> lower = subList(numbers, mid, numbers.size() - 1);
        return max(maxOf(upper), maxOf(lower));
    }
}

vector<int> subList(const vector<int> &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    vector<int> subVec(first, last);
    return subVec;
}