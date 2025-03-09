class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int a=0,b=0;
            for(int n:nums)
            {
                if(b ==0)
                {
                    a=n;
                    b = 1;
                }else if(n == a)
                {
                    b++;
                }else{
                    b--;
                }
            }
            return a;
        }
    };