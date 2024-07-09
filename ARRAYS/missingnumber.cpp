#include<iostream>
using namespace std;
//brute - linear search , better - hashmaps, optimal - sum , XOR
int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    int i,j,s=0,flag;
    int n = sizeof(arr)/sizeof(arr[1]);
    //optimal solution
    int m = 6;
    int sum =m*(m+1)/2;
    for(i = 0; i<n ; i++)
    {
        s += arr[i];
    }
    cout<<sum-s;
    //time complexity  = O(N)
    //space complexity = O(1)

    //brute force
    // for(i = 0; i<n ; i++)
    // {
    //     flag = 0;

    //     for(j = 0; j<n; j++)
    //     {
    //         if(arr[j]==i)
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag==0)
    //     {
    //         cout<<i;
    //     }
    // }
    //time complexity  = O(N*N)
    //space complexity = O(1)
}
