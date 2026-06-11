#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& arr)
{
    int n = arr.size();
    int m = arr[0].size();

    int start_row = 0;
    int end_row = n - 1;
    int start_col = 0;
    int end_col = m - 1;

    int count = 0;
    int total = n * m;

    vector<int> ans;

    while(count < total)
    {
        // Left -> Right
        for(int i = start_col; i <= end_col && count < total; i++)
        {
            ans.push_back(arr[start_row][i]);
            count++;
        }
        start_row++;

        // Top -> Bottom
        for(int i = start_row; i <= end_row && count < total; i++)
        {
            ans.push_back(arr[i][end_col]);
            count++;
        }
        end_col--;

        // Right -> Left
        for(int i = end_col; i >= start_col && count < total; i--)
        {
            ans.push_back(arr[end_row][i]);
            count++;
        }
        end_row--;

        // Bottom -> Top
        for(int i = end_row; i >= start_row && count < total; i--)
        {
            ans.push_back(arr[i][start_col]);
            count++;
        }
        start_col++;
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> ans = spiralMatrix(arr);

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}