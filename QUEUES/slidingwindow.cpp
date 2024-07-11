#include<iostream>
using namespace std;
#include<vector>
#include<deque>
vector<int> FindAns(vector<int> nums, int k)
{
    vector<int> res;
    deque<int> dq;
    int i;
    for(i = 0; i<nums.size(); i++)
    {
        if(!dq.empty() && dq.front()==i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()]<= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1)
        {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = FindAns(nums, k);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    //brute force
    // int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    // int n = sizeof(arr)/sizeof(arr[1]);
    // int k = 3;
    // int i, j;
    // int res[n-k+1];
    // int m = 0;
    // for(i = 0; i<=n-k; i++)
    // {
    //     int max_val = arr[i];
    //     for(j = i+1; j<i+k; j++)
    //     {
    //         if(max_val<arr[j])
    //         {
    //             max_val = arr[j];
    //         }
    //     }
    //     res[m++] = max_val;
    // }
    // for(i = 0; i<n-k+1; i++)
    // {
    //     cout<<res[i]<<" ";
}
