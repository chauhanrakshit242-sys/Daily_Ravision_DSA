#include<bits/stdc++.h>
using namespace std;

vector<int> MaxanMin(vector<int>& arr)
{
    int n = arr.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    return {mini, maxi};
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = MaxanMin(arr);

    cout << "Smallest Element : " << ans[0] << endl;
    cout << "Largest Element : " << ans[1] << endl;

    return 0;
}