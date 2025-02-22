#include <algorithm>
#include <iostream>
using namespace std;

void insert(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int c = arr[i];
        int p = i - 1;
        while (p >= 0 && arr[p] < c)
        {
            arr[p + 1] = arr[p];
            p--;
        }

        arr[p + 1] = c;
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {54, 45, 51, 26, 1};
    int n = 5;
    insert(arr, n);
    print(arr, n);

    return 0;
}