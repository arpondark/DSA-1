#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    while (true)
    {
        n++;
        int a = n / 1000;
        int b = n / 100 % 10;
        int c = n / 10 % 10;
        int d = n % 10;
        if (a != b && a != c && a != d && b != c && b != d && c != d)
        {
            return n;
            break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}