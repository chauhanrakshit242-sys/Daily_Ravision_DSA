#include<bits/stdc++.h>
using namespace std;
bool check_Strobogrammatic(string str ,unordered_map<char,char>map)
{
    int i =0;
    int j =str.length()-1;
    while(i<j)
    {
        if(map[str[i]])
        {
          if(map[str[i]]==str[j])
           {
            i++;
            j--;
           }
           else{
            false;
           }
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str;
    cin>>str;
    unordered_map<char,char>map;
    map.insert({'0','0'});
    map.insert({'1','1'});
    map.insert({'6','9'});
    map.insert({'8','8'});
    map.insert({'9','6'});
    bool ans  = check_Strobogrammatic(str,map);
    if(ans)
    {
    cout<<"It is Strobogrammatic Number";
    }
    else
    {
        cout<<"It  not  Strobogrammatic Number";
    }
    return 0;
}