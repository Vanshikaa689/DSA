#include<iostream>
#include<vector>
using namespace std;

bool isvalid(vector<int> arr)
{
    int five = 0, ten = 0;

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]==5)
        {
            five++;
        }
        else if(arr[i]==10)
        {
            if(five)
            {
                five--;
                ten++;
            }
            else
            {
                return false;
            }
        }
        else if(arr[i] == 20)
        {
            if(five && ten)
            {
                five--;
                ten--;
            }
            else if(five>3)
            {
                five = five -3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<int> arr = {5, 5, 5, 10, 20};

    cout<<isvalid(arr);
}
//time complexity = O(N)
//spcae complexity = O(1)