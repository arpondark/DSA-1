#include <algorithm>
#include <iostream>
using namespace std;

void selection(int arr[], int n)
{
    for (int i = 0; i < n-1 ; i++)
    {

        int smi = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smi])
            {
                smi = j;
            }
        }
        swap(arr[i], arr[smi]);

    }
}
void print(int arr[], int n) {
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[] = {54, 45, 51, 26, 1};
    int n = 5;
    selection(arr, n);
    print(arr, n);
    return 0;
}
