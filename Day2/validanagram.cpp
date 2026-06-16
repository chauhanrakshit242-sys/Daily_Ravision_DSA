#include<bits/stdc++.h>
using namespace std;
// bool valid_anagram( string str1 , string str2)
// {
//     int  n =str1.length();
//     int  m =str2.length();
//     if(n!=m)
//     return false;
//     map<char,int>first;
//     map<char,int>second;
//     for(int i=0;i<str1.length();i++)
//     {
//         first[str1[i]]++;
//         second[str2[i]]++;
//     }
//     if(first== second)
//     {
//         return true;
//     }
//     return false;
// 
bool valid_anagram(string str1, string str2)
{
    int n =str1.length();
    int m = str2.length();
    if(n!=m)
    return false;
    vector<int>freq(26,0);
    for(int i = 0 ; i< str1.size() ;i++)
    {
        freq[str1[i]-'a']++;
    }
    for(int j=0; j < str2.size();j++)
    {
       freq[str2[j]-'a']--;
    }
     for( auto count : freq)
     {
        if(count !=0)
        {
            return false;
        }
     }
     return true;
}
int main()
{
     string str1;
     getline(cin,str1);
     string str2;
     getline(cin, str2);
     bool ans = valid_anagram(str1 , str2);
     if(ans)
     {
        cout<<"Anagram is valid";
     }
     else
     {
        cout<<"Anagram is not Valid";
     }
    return 0;
}
