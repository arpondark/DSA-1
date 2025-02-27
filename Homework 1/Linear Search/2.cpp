#include <bits/stdc++.h>
using namespace std;

int solve(int n, string s)
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]== s[i-1])
        {
            x++;
        }
    }
    return x;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    cout << solve(n,s);
    return  0;
}