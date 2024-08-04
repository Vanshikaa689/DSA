//power set 

#include<iostream>
using namespace std;
#include<vector>
void subseq(int ind, vector<int> seq, vector<int>arr, int n)
{
    if(ind ==n)
    {
        for(auto i: seq)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }

    //take or pick the element 
    seq.push_back(arr[ind]);
    subseq(ind+1, seq, arr, n);
    seq.pop_back();

    //do not pick the element
    subseq(ind+1, seq, arr, n);
}
//time complexity = O(2^n)
//space complexity = O(n)
int main()
{
    vector<int> arr = {3,1,2};
    vector<int> seq;
    subseq(0, seq, arr, arr.size());
    return 0;
}