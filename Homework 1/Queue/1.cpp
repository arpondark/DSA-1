/*
class Solution {
    public:
    int firstUniqChar(string s) {
       vector<int> count(26);
       
       for (const char c : s)
         ++count[c - 'a'];
   
       for (int i = 0; i < s.length(); ++i)
       if (count[s[i] - 'a'] == 1)
       return i;
       
       return -1;
    }
};
*/
#include <bits/stdc++.h>


using namespace std;

int sol(string s) {
   vector<int>alpha(26);
   for(const char c:s)
   {
    alpha[c - 'a']++;
   }
   for(int i=0;i<s.length();i++)
   {
       if(alpha[s[i] - 'a'] == 1)
       {
           return i;
       }
     
   }
   return -1;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout <<"Output:"<< sol(s) << endl;
    return 0;
}


