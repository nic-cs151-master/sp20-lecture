#include <iostream>
#include <string>
using namespace std;

int largestDigit(int num)
{
    num = abs(num);
    if (num < 10)
    {
        return num;
    }
    else //if (num > 0)
    {
        std::cout << num % 10 << ' ' << num / 10 << '\n';
        return std::max(num % 10, largestDigit(num / 10));
    }
    // else
    // {
    //     std::cout << -1 * num % 10 << ' ' << num / 10 << '\n';
    //     return std::max(-num % 10, largestDigit(-num / 10));
    // }
}

bool isPalindrome(string s)
{
    if (s.size() <= 1)
    {
        return true;
    }

    if (isspace(s[0]))
    {
        return isPalindrome(s.substr(1));
    }
    if (isspace(s[s.size() - 1]))
    {
        return isPalindrome(s.substr(0, s.size() - 1));
    }

    if (tolower(s[0]) == tolower(s[s.size() - 1]))
    {
        return isPalindrome(s.substr(1, s.size() - 2));
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "Java";
    cout << s.substr(1, s.size() - 1) << '\n';
    cout << s << " palindrome?" << (isPalindrome(s) ? "true" : "false");

    // std::cout << largestDigit(14263203) << "==6\n";
    // std::cout << largestDigit(-573026) << "==7\n";
    // std::cout << largestDigit(-2) << "==2\n";
    return 0;
}