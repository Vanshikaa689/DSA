#include<iostream>
using namespace std;
int fibb(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fibb(n-1) + fibb(n-2);
}

int main()
{
    cout<<fibb(3);
}
//time complexity = O(2^n)
