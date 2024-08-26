#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr+n);
    sort(dep, dep+n);
    int i = 0, j = 0;
    int cnt = 0;
    int maxcnt = 0;
    while(i<n)
    {
        if(arr[i]<=dep[j])
        {
            cnt = cnt+1;
            i = i+1;
        }
        else
        {
            cnt = cnt-1;
            j = j+1;
        }
        maxcnt = max(maxcnt, cnt);
    }
    return maxcnt;
}
int main()
{
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr)/sizeof(arr[1]);
    cout<<findPlatform(arr, dep, n);
}
//time complexity = 2*O(n+ nlogn)
//space complexity = O(1)

//int arr[] = {900, 945, 955, 1100, 1500, 1800};
//int dep[] = {920, 1130, 1150, 1200, 1900, 2000};
