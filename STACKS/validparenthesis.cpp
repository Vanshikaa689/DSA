#include<iostream>
using namespace std;
#include<stack>
#include<string>
bool valid(stack<char> st, string s, int n)
{
    int i;
        for(i=0; i<n; i++)
    {
        if(s[i]=='(' || s[i]== '['|| s[i]=='{')
        {
            st.push(s[i]);
        }
        else{
            if(st.empty())
            {
                return false;
            }
            char c = st.top();
            st.pop();
            if(s[i]==')'&& c!='('||s[i]==']'&& c!='['||s[i]=='}'&& c!='{')
            {
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
    int i;
    stack<char> st;
    string s = "()[]{[()]}";
    int n = s.size();
    bool ans = valid(st, s, n);
    cout<<ans;
}
