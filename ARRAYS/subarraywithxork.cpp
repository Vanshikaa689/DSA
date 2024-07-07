#include<iostream>
#include <map>
using namespace std;
int main()
{
    int arr[] = {4, 2, 2, 6, 4};
    int n = sizeof(arr)/sizeof(arr[1]);
    //optimal approach
    //is there any subbaray ending at 6 and hacing a xor of k
    //we have xor till 6 we will get k if we have x
    //4 2 2 6 4
    int k = 6;
    int xr = 0;
    int count = 0;
    int i, j;
    map<int, int> mpp;
    mpp[0]=1;//Sets the value at key 0 in the map mpp to 1.
    for(i=0; i<n; i++)
    {
        xr = xr^arr[i];
        int x = xr^k;
        count +=mpp[x]; count += mpp[x];//Adds the value at key x in the map mpp to count.
        mpp[xr]++;//Increments the count of occurrences of xr in the map mpp.
    }
    cout<<count;

    //brute force
    // int i, j;
    // int XOR = 0;
    // int count = 0;
    // for (i = 0; i < n; i++)
    // {
    //     XOR = 0;
    //     for (j = i; j < n; j++)
    //     {
    //         XOR = XOR ^ arr[j];
    //         if(XOR == 6)
    //         {
    //             count++;
    //         }
    //     }
    // }
    // cout<<count;
    //time complexity = o(N^2)
}
