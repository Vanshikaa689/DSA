#include<iostream>
using namespace std;
int main()
{
    int arr[] = {10, 22, 12, 3, 0, 6};
    int n = sizeof(arr)/sizeof(arr[1]);
    int i, j;
    bool leader;
    int maxi = -1;
    //optimal
    for(i=n-1; i>=0; i--)
    {
        if(arr[i]>maxi)
        {
            maxi = arr[i];
            cout<<arr[i]<<" ";
        }
    }

    //brute force
    // for(i=0; i<n; i++)
    // {
    //     leader = true;
    //     for(j=i+1; j<n; j++)
    //     {
    //         if(arr[j]>arr[i])
    //         {
    //             leader = false;
    //             break;
    //         }
    //     }
    //     if(leader == true)
    //     {
    //         cout<<arr[i]<<" ";
    //     }
    // }
    //time complexity = O(N^2)
    //space complexity(worst)= O(N)
}
