#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 1, 1, 6};
    int i, n = sizeof(arr)/sizeof(arr[1]);
    int maxi = 0;
    int count = 0;
    for(i =0; i<n; i++)
    {
        if(arr[i] == 1)
        {
            count++;
            maxi = max(maxi, count);
        }
        else
        {
            count =0;
        }
    }
    cout<<maxi;
}
