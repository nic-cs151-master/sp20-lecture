#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <queue>

template<typename T>
void regularForLoop(T &list, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << list[i] << ' ';
    }
    std::cout << '\n';
}

template<typename T>
void rangedBasedForLoop(T &list)
{
    for (auto elem : list)
    {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}



int main()
{
    std::vector<int> vec{34, 23, 35, 39, 55};

    regularForLoop(vec, vec.size());
    rangedBasedForLoop(vec);
    // for (int elem : vec)
    // {
    //     std::cout << elem << ' ';
    // }
    // std::cout << '\n';

    float array[] = {3.4f, 23.4f, 45.5f, 6.6f, 5.5f};

    regularForLoop(array, 5);
    rangedBasedForLoop(array);

    std::list<int> lst;
    lst.push_back(12);
    lst.push_back(14);
    lst.push_back(24);
    lst.push_back(343);

    rangedBasedForLoop(lst);

    std::stack<int> stk;
    stk.push(12);
    stk.push(34);
    stk.push(56);
    stk.push(89);

    std::queue<int> que;
    que.push(34);
    que.push(35);
    que.push(53);
    que.push(36);

    

    return 0;
}