#include<iostream>
#include<vector>
using namespace std;

void subseq(int ind, vector<int> &seq, int s, int sum, vector<int> &arr, int n)
{
    if(ind == n)
    {
        if(sum == s)
        {
            for(auto i: seq)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return; // Return after processing the base case
    }

    // take or pick the element 
    seq.push_back(arr[ind]);
    sum += arr[ind];
    subseq(ind + 1, seq, s, sum, arr, n);
    sum -= arr[ind];
    seq.pop_back();

    // do not pick the element
    subseq(ind + 1, seq, s, sum, arr, n);
}

// time complexity = O(2^n)
// space complexity = O(n)
int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> seq;
    int sum = 2;
    subseq(0, seq, sum, 0, arr, arr.size());
    return 0;
}
