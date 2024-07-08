#include<iostream>
using namespace std;
int main()
{
    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i, j;
    //optimal solution
    //using observation
    int pre = 1, suff  =1;
    int ans = INT_MIN;
    for(i=0; i<n; i++)
    {
        if(pre==0)
        {
            pre = 1;
        }
        if(suff==0)
        {
            suff = 1;
        }
        pre = pre*arr[i];
        suff = suff*arr[n-i-1];
        ans = max(ans, max(pre, suff));
    }
    cout<<ans;




    //brute force
    // int max = 0;
    // for(i = 0; i<n; i++)
    // {
    //     int prod = 1;
    //     for(j = i; j<n; j++)
    //     {
    //         prod = prod*arr[j];
    //         if(prod > max)
    //         {
    //             max = prod;
    //         }
    //     }
    // }
    // cout<<max;
    //time complexity = O(N^2)
}
