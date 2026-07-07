class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxi = 0;
        int maxCharcount = 0;
        vector<int> arr(26, 0);

        int i = 0;
        int j = 0;

        while(j < n)
        {
            arr[s[j] - 'A']++;
            maxCharcount = max(maxCharcount, arr[s[j] - 'A']);

            int ops = (j - i + 1) - maxCharcount;

            while(ops > k)
            {
                arr[s[i] - 'A']--;
                i++;

                ops = (j - i + 1) - maxCharcount;
            }

            maxi = max(maxi, j - i + 1);

            j++;
        }

        return maxi;
    }
};