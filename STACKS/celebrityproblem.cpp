#include<iostream>
using namespace std;
#include<vector>
#include<stack>
int isCelebrity(vector<vector<int>> m)
{
    stack<int> st;
    int i;
    int r = m.size();
    int c = m[0].size();
    for(i = 0;i<r; i++)
    {
        st.push(i);
    }
    while(st.size()!=1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if(m[a][b]==1)
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }
    int ans = st.top();
    int y = 1;
    for(i=0; i<c; i++)
    {
        if(m[ans][i]==0)
        {
            y = 1;
        }
        else
        {
            y=0;
        }
    }
    for(i=0; i<r; i++)
    {
        if(i == ans)
        {
            continue;
        }
        if(m[i][ans]==1)
        {
            y = 1;
        }
        else
        {
            y=0;
        }
    }
    if(y=1)
    {
        return ans;
    }

}
int main()
{
    vector<vector<int>> m = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int ans = isCelebrity(m);
    cout<<ans;
    return 0;
}
