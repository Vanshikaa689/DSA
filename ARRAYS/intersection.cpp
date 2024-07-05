#include<iostream>
using namespace std;
int main()
{   //optimal 
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1)/sizeof(arr1[1]);
    int n2 = sizeof(arr2)/sizeof(arr2[1]);
    int i=0,j=0;
    int k = 0;
    int inter[min(n1, n2)];
    while(i!=n1&&j!=n2)
    {
        if(arr1[i]==arr2[j])
        {
            inter[k] = arr1[i];
            k++;
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else 
        {
            j++;
        }
    }
    for(i = 0; i<k; i++)
    {
        cout<<inter[i]<<" ";
    }
    //time complexity = O(n1+n2)
    //space complexity = O(1)


    //brute force
    //compare each element in arr1 to all elements in arr2
    //maintain a visited array of size of arr2 initialised wih 0s
    // if arr[i] = arr2[j]&& vis[j]==0
    // else arr2[j]>arr1[i]
    //break inside both if and else
    // dont increment i and j inside the loop

    // int arr1[] = {1, 2, 3, 4, 5};
    // int arr2[] = {1, 2, 3, 4, 5};
    // int n1 = sizeof(arr1)/sizeof(arr1[1]);
    // int n2 = sizeof(arr2)/sizeof(arr2[1]);
    // int vis[n2] = {0};
    // int inter[min(n1, n2)];
    // int k  = 0;
    // int i, j;
    // for(i = 0; i<n1; i++)
    // {
    //     for(j = 0; j<n2; j++)
    //     {
    //         if(arr1[i] == arr2[j]&& vis[j]==0)
    //         {
    //             inter[k] = arr1[i];
    //             k++;
    //             vis[j] = 1;
    //             break;
    //         }
    //         else if(arr2[j]>arr1[i])
    //         {
    //             break;
    //         }
    //     }

    // }
    // int m = sizeof(inter)/sizeof(inter[1]);
    // for(i = 0; i<m ; i++)
    //     {
    //         cout<<inter[i]<<" ";
    //     }
    //time complexity = O(n1*n2)
    //space complexity = O(n2)
}
