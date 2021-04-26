#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <utility> // pair, make_pair

using std::string;
using std::cout;
using std::map;
using std::pair;
using std::make_pair;
using std::stack;

int max(int a, int b);  
int lcs(const string &str1, const string &str2, stack<char> &sub);
int lcs(const string &str1, const string &str2, int m, int n, map<pair<int,int>, int> &results);
  
int main()  
{  
    // string str1 = "ABCDGH";
    // string str2 = "AEDFHR"; 

    // string str1 = "AGGTAB";  
    // string str2 = "GXTXAYB"; 

    string str1 = "CCGATGATCATTGCCAGTCCACCGATTGTGAGAACGACAGCGACTCCAGC";
    string str2 = "CCGATGACTTTTGCAGCTCCACCGATTTTGGTCCAGC";
   
    cout << "str1: " << str1 << '\n';
    cout << "str2: " << str2 << '\n';

    stack<char> subsequence;
    cout << "Length of LCS is " 
         << lcs(str1, str2, subsequence) << '\n';  
    
    while(!subsequence.empty())
    {
        cout << subsequence.top();
        subsequence.pop();
    }
    cout << '\n';

    return 0;  
}  

/**
 * @brief Returns length of LCS for str1[0..m-1], str2[0..n-1] 
 * @param str1 first string
 * @param str2 second string
 * @return length of LCS for str1 and str2
 */
int lcs(const string &str1, const string &str2, stack<char> &sub)
{
    int m = str1.length();  
    int n = str2.length(); 
    map<pair<int,int>, int> results;
    
    int x = lcs(str1, str2, m, n, results);
    
    // TODO: get the subsequence
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (str1[i-1] == str2[j-1])
        {
            sub.push(str1[i-1]);
            --i;
            --j;
        }
        else if (results[make_pair(i-1,j)] > results[make_pair(i,j-1)])
        {
            --i;
        }
        else
        {
            --j;
        }
        
    }

    return x;
}

/**
 * @brief Returns length of LCS for str1[0..m-1], str2[0..n-1] 
 * @param str1 first string
 * @param str2 second string
 * @param m length of str1, represent the index
 * @param n length of str2, represent the index
 * @return length of LCS for str1 and str2
 */
int lcs(const string &str1, const string &str2, int m, int n, map<pair<int,int>, int> &results)  
{  
    if (m == 0 || n == 0)  
        return 0;  

    if (results.find(make_pair(m,n)) != results.end())
        return results[make_pair(m,n)];

    if (str1[m-1] == str2[n-1])  
    {
        results[make_pair(m,n)] = 1 + lcs(str1, str2, m-1, n-1, results);  
        return results[make_pair(m,n)];
    }
    else
    {
        results[make_pair(m,n)] = max(lcs(str1, str2, m, n-1, results), lcs(str1, str2, m-1, n, results));
        return results[make_pair(m,n)];  
    }
}  
  
/**
 * @brief Utility function to get max of 2 integers 
 * @return maximum value between a and b
 */
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  