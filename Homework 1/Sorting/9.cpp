class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            int m = n;
            for(int i=0;i<n;i++)
            {
                m ^= (i^nums[i]);
            }
            return m;
        }
    };
