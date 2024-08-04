#include<iostream>
using namespace std;
bool ispalindrome(int i, int arr[],int n)
{
    if(i>n/2)
    {
        return true;
    }
    if(arr[i]!=arr[n-i-1])
    {
        return false;
    }
    return ispalindrome(i+1, arr, 5);
}
int main()
{
    int arr[] = {1, 2, 3, 2, 1};
    cout<<ispalindrome(0, arr, 5);
}