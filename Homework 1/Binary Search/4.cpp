class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l =0;
        int h = nums.size()-1;
        while(l<h)
        {
            int m = (l+h)/2;
            if(nums[m]>=nums[m+1] )
            {
                h=m;

            }
            else{
                l= m+1;
            }
            
        }
            return l;
    }
};