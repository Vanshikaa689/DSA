#include<iostream>
using namespace std;

int nsum(int n, int i)
{
    if(n==0)
    {
        return i;
    }
    return nsum(n-1, i+n);
}
int nsum2(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n + nsum2(n-1);
}
int main()
{
    int n = 5;
    int s = nsum(n, 0);
    cout<<s;
    int s2 = nsum2(n);
    cout<<s2;
}