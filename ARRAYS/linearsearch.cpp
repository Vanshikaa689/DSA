#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 4, 5, 6};
    int i, key = 5;
    int k=0;
    int n = sizeof(arr)/sizeof(arr[1]);
    for(i = 0; i<n; i++)
    {
        if(arr[i] == key)
        {
            k = i;
            break;
        }
        else
        {
            k =-1;
        }
    }
    if(k==-1)
    {
        cout<<"not found";
    }
    else{
        cout<<k;
    }
}
