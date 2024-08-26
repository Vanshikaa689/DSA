#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int cookies(vector<int> greed, vector<int> capacity)
{
    int n = greed.size();
    int m = capacity.size();

    sort(greed.begin(), greed.end());
    sort(capacity.begin(), capacity.end());
    int l = 0, r = 0;

    while(l < m)
    {
        if(greed[r]<=capacity[l])
        {
            l++;
            r++;
        }
        else if(greed[r]>capacity[l])
        {
            l++;
        }
    }
    return r;

}
int main()
{
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> capacity = {4, 2, 1, 2, 1, 3};

    cout<<cookies(greed, capacity);
}
//time complexity = O(NlogN) + Mlog(N) + M
//space complexity = O(1)
