#include<iostream>
using namespace std;
int main()
{
    int arr[] = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
    int n = sizeof(arr)/sizeof(arr[1]);
    int i=0, j, c=0;
    int el = arr[0], cnt=0;
    //optimal solution - MOORE'S VOTING ALGORITHM
    //1.Apply moore's voting algo 
    int k = 0;
    while(i<n)
    {
        if(arr[i+1]==el)
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            i++;
        }
        if(cnt==0)
        {
            el = arr[i];
            cnt++;
        }
    }
    //2.verify that he element is majority
    for(j = 0; j<n; j++)
    {
        if(el==arr[j])
        {
            c++;
        }
    }
    if(c>n/2)
    {
        cout<<el;
    }
    //time complexity = O(N)
    //pace complexity = O(1)
    






    //brute force
    // for(i = 0; i<n; i++)
    // {
    //     count = 0;
    //     for(j = i+1; j<n; j++)
    //     {
    //         if(arr[j]==arr[i])
    //         {
    //             count++;
    //         }
    //     }
    //     if(count>=n/2)
    //     {
    //         cout<<arr[i];
    //     }
    // }
    //time complexity = O(N^2)
    //space complexity = O(1)

}
