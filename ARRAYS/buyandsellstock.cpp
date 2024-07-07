#include<iostream>
using namespace std;
#include<vector>
  int maxProfit(vector<int> &prices)
  {
    int ans = 0;
    int MIN = INT_MAX;

    for (auto &i : prices)
    {
      MIN = min(MIN, i);
      ans = max(ans, i - MIN);
    }

    return ans;
  }
int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr);
}
