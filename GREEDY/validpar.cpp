#include<iostream>
using namespace std;
#include<vector>
bool valid(string s, int ind, int cnt)
{
    if(cnt<0)
    {
        return false;
    }
    if(ind==s.size())
    {
        return cnt==0;
    }
    if(s[ind] =='(')
    {
        return valid(s, ind+1, cnt+1);
    }
    else if(s[ind] ==')')
    {
        return valid(s, ind+1, cnt-1);
    }
    return valid(s, ind+1, cnt+1) or valid(s, ind+1, cnt-1) or valid(s, ind+1, cnt);

}
int main()
{
    string s = "(()(())";
    cout<<valid(s, 0, 0);
}