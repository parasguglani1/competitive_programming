/* Remove Duplicates Recursively
Send Feedback
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :

xyzwz */
#include <bits/stdc++.h>
using namespace std;
char previous = ' ';

string removeConsDuplicates(string str)
{
    if (!str.empty())
    {
            if (str[0] == previous)
        {
            str = removeConsDuplicates(str.substr(1));
        }
        else
        {
            previous=str[0];
            str = str[0] + removeConsDuplicates(str.substr(1));
        }
    }
    return str;
}

//char array
void consecutiveDuplicate(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] == str[1])
    {
        int i = 1;
        for (; str[i] != '\0'; i++)
        {
            str[i - 1] = str[i];
        }
        str[i - 1] = str[i];
        consecutiveDuplicate(str);
    }
    else
    {
        consecutiveDuplicate(str + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        str = removeConsDuplicates(str);
        cout << str << endl;
    }
    return 0;
}