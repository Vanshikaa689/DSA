#include<iostream>
using namespace std;
#include<stack>
#include<vector>
int LargestRectangle(vector<int> arr)
{
    int i;
    int n = arr.size();
    stack<int> st;
    int ls[n];
    int rs[n];
    for(i= 0; i<n; i++)
    {
        while(!st.empty() && arr[st.top()]>= arr[i])
        {
            st.pop();
        }
 
        if(st.empty())
        {
            ls[i] = 0;
        }
        else{
            ls[i] = st.top()+1;
        }
        st.push(i);

    }
    while(!st.empty())
    {
        st.pop();
    }
    for(i = n-1; i>=0; i--)
    {
        while(!st.empty() && arr[st.top()]>= arr[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            rs[i] = n-1;
        }
        else{
            rs[i] = st.top()-1;
        }
        st.push(i);

    }
    int maxi = 0;
    for(i= 0; i<n; i++)
    {
        maxi = max(maxi, arr[i]*(rs[i]-ls[i]+1));
    }
    return maxi;
}
int main()
{
    vector<int> arr = {2, 1, 5, 6, 3, 1};
    cout<<LargestRectangle(arr);
}
