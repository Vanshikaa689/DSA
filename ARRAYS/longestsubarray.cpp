#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int n = sizeof(arr)/sizeof(arr[1]);
    int len=0, i=0, j=0, sum=0;
    //optimal - move and shrink approach
    int k = 6;
    while(j<n)
    {
            sum += arr[j];
       
        while(i<=j&&sum>k)
        {
            sum-=arr[i];
            i++;
        }
        if(sum==k)
        {
            len = max(len, j-i+1);
        }
        j++;
    }
    cout<<len;

    //brute force
    // int k = 3;
    // for(i = 0; i<n; i++)
    // {
    //     sum = 0;
    //     for(j = i; j<n ; j++)
    //     {
    //         sum = sum+ arr[j];
    //         if(sum==k)
    //         {
    //             len = max(len, j-i+1);
    //         }
    //     }
    // }
    // cout<<len;
    //time complexity = O(N^2)
}
