class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int pc = 0, nc = 0;
    
            for (int num : nums) {
                (num > 0) ? pc++ : (num < 0 ? nc++ : 0);
            }
    
            return max(pc, nc);
        }
    };
    