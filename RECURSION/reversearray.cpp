#include<iostream>
using namespace std;

void reversearr(int arr[], int start, int end)
{
    if(start>=end)
    {
        return;
    }
    swap(arr[start], arr[end]);
    reversearr(arr, start+1, end-1);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    reversearr(arr, 0, 5-1);
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }
}