class Solution {
    public:
        int maximumWealth(vector<vector<int>>& accounts) {
           int arp = 0;
            for(auto& x :accounts)
            {
                arp =max(arp,accumulate(x.begin(),x.end(),0));
            }
            return arp;
        }
    };