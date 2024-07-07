#include<iostream>
using namespace std;
int main()
{
    int arr[] = {3, 1,-2, -5, 2, -4};
    int i, j=0, k=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    // //optimal
    // int ans[n];
    // for(i=0; i<n; i++)
    // {
    //     if(arr[i]>=0)
    //     {
    //         ans[2*j] = arr[i];
    //         j++;
    //     }
    //     else{
    //         ans[2*k+1] = arr[i];
    //         k++;
    //     }
    // }
    // for(i=0; i<n;i++)
    // {
    //     cout<<ans[i]<<" ";
    // }





//  brute force
    int pos[n/2];
    int neg[n/2];
    for(i = 0; i<n; i++)
    {
        if(arr[i]>=0)
        {
            pos[j] = arr[i];
            j++;
        }
        if(arr[i]<0)
        {
            neg[k] = arr[i];
            k++;
        }
    }
    int po = sizeof(pos)/sizeof(pos[0]);
    int ne = sizeof(neg)/sizeof(neg[0]);
    int mini = min(po, ne);

    for(i= 0; i<mini; i++)
    {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
    }
    int ind = 2*mini;
    for(i = 0; i<n-ind; i++)
    {
        if(po>ne)
        {
            arr[ind] = pos[mini];
            ind++;
            mini++;
        }
        else if(ne>po)
        {
            arr[ind] = neg[mini];
            ind++;
            mini++;
        }
    }
    for(i= 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    //time complexity = O(N+N/2)
    //space complexity = O(N)
}
