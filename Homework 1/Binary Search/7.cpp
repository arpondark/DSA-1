class Solution {
    public:
        int mySqrt(int x) {
            unsigned l =1;
            unsigned h = x+1u;
              while (l < h) {
            unsigned m = (l + h) / 2;
           (m > x / m)? h=m :l = m + 1;
           
            
        }
        return l - 1;
            
        }
    };