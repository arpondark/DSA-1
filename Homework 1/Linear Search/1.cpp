#include <bits/stdc++.h>
using namespace std;
int find(int a[],int n)
{
    int even=0,odd=0;
    int eIndex,oIndex;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            even++;
            eIndex=i+1;
        }
        else
        {
            odd++;
            oIndex=i+1;
        }
    }
    return (even == 1)?eIndex:oIndex;


}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << find(a,n);
    return 0;
}