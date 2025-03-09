#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
     int minMovesToSeat(vector<int>& seats, vector<int>& students) {
       int ans = 0;
   
       sort(seats.begin(),seats.end());
       sort(students.begin(),students.end()); //we can use ranges::sort(x) 
   
       for (int i = 0; i < seats.size(); ++i)
         ans += abs(seats[i] - students[i]);
   
       return ans;
     }
   };