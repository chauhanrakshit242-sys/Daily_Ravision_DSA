#include<bits/stdc++.h>
using namespace std;
// It is recusion 
// int solve(vector<int>& num, int x)
// {
//     if(x==0)
//     {
//         return 0;
//     }
//     if(x < 0)
//     {
//         return INT_MAX;
//     }
//     int mini = INT_MAX;
//     for(int i=0;i<num.size();i++)
//     {
//         int ans = solve(num ,x -num[i]);
//         if(ans!=INT_MAX)
//         {
//             mini = min(mini,  1 + ans);
//         }
//     }
//     return mini;
// }

// 
// Tabulation
int solve(vector<int>& num, int x)
{
    vector<int>dp(x+1, INT_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++)
    {
       for(int j=0;j<num.size();j++)
        {
          if( i - num[j]>=0 && dp[i-num[j]]!=INT_MAX)
          {
          dp[i]= min(dp[i] ,dp[i-num[j]]+ 1);
          }
        }
    }
    if(dp[x]==INT_MAX)
    {
        return -1;
    }
    else{
        return dp[x];
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    int x;
    cin>>x;
    vector<int> dp(x+1 ,-1);
    int ans =solve(num,x);
    if(ans==INT_MAX)
    {
        cout<<"-1";
    }
    else
    {
        cout<<ans;
    }
    return 0;
}