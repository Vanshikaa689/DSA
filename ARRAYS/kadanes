#include<iostream>
using namespace std;
//max subarray sum
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int i,j, k,n = sizeof(arr)/sizeof(arr[1]);
    int sum = 0;
    int ansstart=-1, ansend = -1;
    int start= 0;
    int maxi = INT_MIN;

    //optimal
    for(i =0; i<n; i++)
    {
        if(sum == 0)
        {
            start = i;//new start whenever sum is 0
        }
        sum += arr[i];
        if(sum > maxi)
        {
            maxi = sum;
            ansstart = start;
            ansend = i;
        }
        if(sum<0)
        {
            sum = 0;
        }
    }
    cout<<maxi<<"\n";
    for(i = ansstart; i<=ansend; i++)
    {
        cout<<arr[i]<<" ";
    }
    //time complexity = O(N)
    //space complexity = O(1)

    



    //brute force
    // for(i=0; i<n; i++)
    // {
    //     sum = arr[i];
    //     for(j = i;j<n; j++)
    //     {
    //         sum = sum+arr[j];
    //         maxi = max(sum, maxi);
    //     }
    // }
    //time complexit y= O(N^2)
    //space complexity = O(1)
}
