class Solution {
    public:
        vector<int> targetIndices(vector<int>& nums, int target) {
            vector<int> ans;
            const int count = std::count(nums.begin(), nums.end(), target);
            int lessThan = std::count_if(nums.begin(), nums.end(), [target](int num) { return num < target; });
    
            for (int i = 0; i < count; ++i)
                ans.push_back(lessThan++);
    
            return ans;
        }
    };