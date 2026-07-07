class Solution {
public:
    bool check_valid(vector<int>& base, vector<int>& newbase)
    {
        return base[0] <= newbase[0] &&
               base[1] <= newbase[1] &&
               base[2] <= newbase[2];
    }

    int solve(vector<vector<int>>& arr) {

        int n = arr.size();

        vector<int> curr_row(n + 1, 0);
        vector<int> next_row(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {

            for (int prev = curr - 1; prev >= -1; prev--) {

                int include = 0;

                if (prev == -1 || check_valid(arr[prev], arr[curr])) {
                    include = arr[curr][2] + next_row[curr + 1];
                }

                int exclude = next_row[prev + 1];

                curr_row[prev + 1] = max(include, exclude);
            }

            next_row = curr_row;
        }

        return next_row[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {

        for (auto &a : cuboids) {
            sort(a.begin(), a.end());
        }

        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids);
    }
};