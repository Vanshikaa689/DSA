#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int avgwt(vector<int> bt)
{
    sort(bt.begin(), bt.end());
    int t = 0;
    vector<int> wt(bt.size());
    int wtt = 0;
    for(int i = 0; i<bt.size(); i++)
    {
        if(i == 0)
        {
            wt[i] = 0;
        }
        else
        {
            wt[i] = t;
        }
        t = t + bt[i];
        wtt = wtt+wt[i];
    }
    return wtt/bt.size();
}
int main()
{
    vector<int> arr = {4, 3, 7, 1, 2};
    cout<<avgwt(arr);
}