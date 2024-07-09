#include<iostream>
using namespace std;
int main()
{
// optiml solution
    //2 pointers i and j
    // find first zeroth element j stores its index 
    // move i to j+1
    //if arr[i] !=0 swap arr[i] and arr[j] and j++
    //i always moves forward

    //Time complexity = O(N)
    //Space complexity = O(1)

    int arr[] = {1, 0, 2, 3, 5, 0 , 0, 6, 0, 8};
    int i, j;
    int n = sizeof(arr)/sizeof(arr[1]);
    for(i = 0; i<n; i++)
    {
        if(arr[i]==0)
        {
            j = i;
            break;
        }
    }
    for(i = j+1; i<n; i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for(i = 0; i<n; i++)
    {
        cout<<arr[i];
    }
//brute force 
    // int arr[] = {1, 2, 0, 0, 0, 4, 5, 0, 6, 7};
    // int n = sizeof(arr)/sizeof(arr[1]);
    // int i;
    // int count = 0;
    // int temp[n];
    // for(i = 0; i<n; i++)
    // {
    //     if(arr[i]!=0)
    //     {
    //         temp[count++] = arr[i];
    //     }
    // }
    // for(i = 0; i<n; i++)
    // {
    //     if(i>count)
    //     {
    //         arr[i] = 0;
    //     }
    //     else{
    //         arr[i] = temp[i];
    //     }
    // }
    // for(i=0; i<n; i++)
    // {
    //     cout<<arr[i];
    // }
    //worst case = O(N)
}
