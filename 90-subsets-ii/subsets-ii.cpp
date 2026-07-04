class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& temp,
               set<vector<int>>& output)
    {
        int n = nums.size();

        if (index == n)
        {
            output.insert(temp);
            return;
        }

        // Include
        temp.push_back(nums[index]);
        solve(nums, index + 1, temp, output);

        // Backtrack
        temp.pop_back();

        // Exclude
        solve(nums, index + 1, temp, output);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        set<vector<int>> output;
        vector<int> temp;

        solve(nums, 0, temp, output);

        return vector<vector<int>>(output.begin(), output.end());
    }
};