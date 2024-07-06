#include<iostream>
using namespace std;
int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0};
    int n = sizeof(arr)/sizeof(arr[1]);
    int i, cnt1=0, cnt2=0, cnt3=0;
    //brute force - sort the array using merge sort 
    //better 
    // for(i = 0;i<n; i++)
    // {
    //     if(arr[i]==0)
    //     {
    //         cnt1++;
    //     }
    //     if(arr[i]==1)
    //     {
    //         cnt2++;
    //     }
    //     if(arr[i]==2)
    //     {
    //         cnt3++;
    //     }
    // }
    // cout<<cnt1<<cnt2<<cnt3<<"\n";
    // for(i = 0; i<cnt1; i++)
    // {
    //     arr[i] = 0;
    // }
    // for(i = cnt1; i<cnt1+cnt2; i++)
    // {
    //     arr[i] = 1;
    // }
    // for(i = cnt2+cnt1; i<n; i++)
    // {
    //     arr[i] = 2;
    // }
    // for(i = 0; i<n; i++)
    // {
    //     cout<<arr[i];
    // }

    //optimal - using DUTCH NATIONAL FLAG ALGORITHM
    //[0 ... LOW-1] -> 0 -> extreme left
    //[LOW ... MID-1] -> 1 -> in between
    //[HIGH+1 ... n-1] -> 2 -> extreme right
    //[MID ... HIGH] -> random -> 0, 1, 2
    //we need to dort the undorted portion 
    //our entire array is unsorted so mid is first element and high is last

    //a[mid] = 0
    //swap(mid, low)
    //low++, mid++

    //a[mid] = 1
    //mid++


    //a[mid] = 2
    //swap(mid, high)
    //no  matter whteher at high there is 0, 1, 2
    //high--
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }

    }
    for(i = 0;i<n; i++)
    {
        cout<<arr[i];
    }
    //time complexity = O(N)
    //space complexity = O(1)
}
