#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    int n = arr.size();
    int i, ind = -1;
    //brute force
    //1.generate all permutations
    //2.linear search
    //3.next index


    //optimal
    //longer prefix match
    //a[i]<a[i+1]
    //find > one but the smallest one so that you stay close
    //try to place rest in sortedd array
    for(i = n-2; i>=0; i--)//finding break point
    {
        if(arr[i]<arr[i+1])
        {
            ind = i;
            break;
        }
    }
    if(ind ==-1)
    {
        reverse(arr.begin(), arr.end());
    }
    else
    {
        for(i=n-1; i>=ind; i--)
        {
            if(arr[i]>arr[ind])
            {
                swap(arr[i], arr[ind]);
                break;
            }
        }
        reverse(arr.begin() + ind + 1, arr.end());
    }
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}
