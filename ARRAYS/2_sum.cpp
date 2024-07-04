#include<iostream>
using namespace std;

int main()
{
    int arr[] = {2, 6, 5, 8, 11};
    int n = sizeof(arr)/sizeof(arr[1]);
    int target = 14;
    int i=0, j=n-1;
    int sum = 0;
    //optimal solution
    // first sort the array using merge sort if not already sorted
    while(i<j)
    {
        sum= arr[i]+arr[j];
        if(sum==target)
        {
            cout<<"yes";
            break;
        }
        else if(sum>target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    if(sum!=target)
    {
        cout<<"no";
    }
    //time cpmlexity = O(N)
    //space complexity = O(1)
    //brute force
    // for(i = 0; i<n; i++)
    // {
    //     for(j = i+1; j<n; j++)
    //     {
    //         if(arr[i]+arr[j]==target)
    //         {
    //             cout<<i<<" "<<j;
    //         }
    //     }
    // }
    //time complexity = O(N^2)
    //space complexity = O(1)
}

