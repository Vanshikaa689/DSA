#include<iostream>
using namespace std;

int main()
{
    int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    int n = sizeof(arr)/sizeof(arr[1]);
    int i, j;
    //optimal - transpose and reverse each row
    //for 0 you travel from 1 -> 3
    //for 1 you travel from 2-> 3

    for(i = 0; i<n-1; i++)
    {
        for(j = i+1; j<n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(arr[i][j], arr[i][n - j - 1]);
        }
    }

    // Print the rotated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //brute force 
    //[0][0]-> [0][3]
    //[0][1]-> [1][3]
    //[0][2]-> [2][3]
    //[0][3]-> [3][3]
    // int ans[n][n];

    // for(i = 0; i<n; i++)
    // {
    //     for(j = 0; j<n; j++)
    //     {
    //         ans[j][n-1-i] = arr[i][j];
    //     }
    // }
    // for(i=0; i<n; i++)
    // {
    //     for(j = 0; j<n; j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //time complexity and space complexity =   O(N^2)
}
