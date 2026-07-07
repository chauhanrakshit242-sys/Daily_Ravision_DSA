class Solution {
public:
    int nextIndex(vector<int>& nums, bool isPos, int curr)
    {
        bool dir = nums[curr] > 0;

        if(dir != isPos)
            return -1;

        int n = nums.size();
        int next = ((curr + nums[curr]) % n + n) % n;

        if(next == curr)
            return -1;

        return next;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
                continue;

            bool isPos = nums[i] > 0;

            int slow = i;
            int fast = i;

            while(true)
            {
                slow = nextIndex(nums, isPos, slow);
                if(slow == -1)
                    break;

                fast = nextIndex(nums, isPos, fast);
                if(fast == -1)
                    break;

                fast = nextIndex(nums, isPos, fast);
                if(fast == -1)
                    break;

                if(slow == fast)
                    return true;
            }

            int curr = i;

            while(nums[curr] != 0 && (nums[curr] > 0) == isPos)
            {
                int next = ((curr + nums[curr]) % n + n) % n;
                nums[curr] = 0;
                curr = next;
            }
        }

        return false;
    }
};