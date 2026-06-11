#include<bits/stdc++.h>
using namespace std;

bool is_valid(char ch)
{
    return ('A' <= ch && ch <= 'Z') ||
           ('a' <= ch && ch <= 'z') ||
           ('0' <= ch && ch <= '9');
}

char toLowerCase(char ch)
{
    if('A' <= ch && ch <= 'Z')
    {
        return ch - 'A' + 'a';
    }
    return ch;
}

bool check(string str)
{
    int start = 0;
    int end = str.length() - 1;

    while(start < end)
    {
        if(str[start] != str[end])
        {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

bool check_palindrome_ans(string str)
{
    string ans = "";

    for(char ch : str)
    {
        if(is_valid(ch))
        {
            ans.push_back(toLowerCase(ch));
        }
    }

    return check(ans);
}

int main()
{
    string str;

    getline(cin, str);

    bool check_palindrome = check_palindrome_ans(str);

    if(check_palindrome)
    {
        cout << "It is Palindrome" << endl;
    }
    else
    {
        cout << "It is not Palindrome" << endl;
    }

    return 0;
}