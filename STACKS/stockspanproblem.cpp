#include<iostream>
using namespace std;
#include<vector>
#include<stack>
vector<int> stocks(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    stack<int> st;
    for(int i = 0; i<n; i++)
    {
        while(!st.empty() && arr[st.top()]<=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            ans.push_back(i+1);
        }
        else{
            ans.push_back(i-st.top());
        }
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> ans = stocks(arr);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
