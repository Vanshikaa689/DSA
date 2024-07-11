#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<algorithm>
vector<int> findele(stack<int> st, int arr[], int n)
{
    int i;
    vector<int> nge;
    for(i= 2*n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()<=arr[i%n])
        {
            st.pop();
        }
        if(i<n)
        {
            if(!st.empty())
            {
                nge.push_back(st.top());
            }
            else
            {
                nge.push_back(-1);
            }
        }
        st.push(arr[i%n]);
    }
    reverse(nge.begin(), nge.end());
    return nge;

}

int main()
{
    stack<int> st;
    int arr[] = {2, 10, 12, 1, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> nge;
    nge = findele(st, arr, n);
    for(auto i:nge)
    {
        cout<<i<<" ";
    }
    return 0;
}
