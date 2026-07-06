class Solution {
public:
    int calu(vector<int>& nums, int curr)
    {
        int n = nums.size();
        return ((curr + nums[curr]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            set<int> st;

            bool isPos = nums[i] > 0;

            int curr = i;

            while(true)
            {
                int next = calu(nums, curr);

                // Single element loop is not allowed
                if(next == curr)
                    break;

                if(isPos)
                {
                    if(nums[next] < 0)
                    {
                        break;
                    }
                    else
                    {
                        if(st.find(next) != st.end())
                        {
                            return true;
                        }

                        st.insert(next);
                    }
                }
                else
                {
                    if(nums[next] > 0)
                    {
                        break;
                    }
                    else
                    {
                        if(st.find(next) != st.end())
                        {
                            return true;
                        }

                        st.insert(next);
                    }
                }

                curr = next;
            }
        }

        return false;
    }
};