class Solution {
    public:
     int findMin(vector<int>& nums) {
       int l = 0;
       int h = nums.size() - 1;
   
       while (l < h) {
         const int m = (l + h) / 2;
         (nums[m] < nums[h])? h = m : l = m + 1;
       }
   
       return nums[l];
     }
   };