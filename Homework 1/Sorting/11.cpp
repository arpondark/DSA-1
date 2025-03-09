using namespace std;
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> ar(nums.begin(),nums.end());
        while(ar.find(original) != ar.end())
        {
            original *=2;
        }
        return original;
    }
};