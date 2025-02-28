class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int d = 0,c=0;
            for(int i: nums)
            {
                while(i)
                {
                    i/=10;
                    d++;
                }
                if(d%2==0)
                {
                    c++;
                }
            }
            return c;
            
        }
    };