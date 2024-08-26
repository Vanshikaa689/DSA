#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

bool isPossible(vector<int> arr)
{
    int m = arr.size();
    int maxInd = 0;
    for(int i = 0; i<m ; i++)
    {
        if(i>maxInd)
        {
            return false;
        }
        maxInd = max(maxInd, i+arr[i]);
    }
    return true;

}
int main()
{
    vector<int> arr = {1, 2, 4, 1, 1, 0, 2, 5};
    cout<<isPossible(arr);
}
//time complexity - O(n)
//space complexity = O(1)