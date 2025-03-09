class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length())
            {
                return false;
            }
            vector<int> c(26);
            for(char i:s)
            {
                ++c[i - 'a'];
            }
            for(char i:t)
            {
                 --c[i - 'a'];
            }
            for(int i=0;i<26;i++)
            {
                if(c[i]!=0)
                {
                    return false;
                }
            }
            return true;
            
        }
    };