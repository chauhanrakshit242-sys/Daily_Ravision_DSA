#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int>& arr , int n)
{
    int start =0;
    int end =n-1;
    while(start < end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of the Element you want add in array:";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Original  Array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    reverse(arr ,n);
    cout<<"Reverse Array :";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
