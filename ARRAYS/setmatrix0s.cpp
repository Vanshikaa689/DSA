#include<iostream>
using namespace std;
// void markCol(int arr[][4], int j, int n)
// {
//     int i;
//     for(i=0; i<n; i++)
//     {
//         if(arr[i][j]!=0)
//         {
//             arr[i][j] = -1;
//         }
//     }
// }
// void markRow(int arr[][4], int i, int n)
// {
//     int j;
//     for(j=0; j<n; j++)
//     {
//         if(arr[i][j]!=0)
//         {
//             arr[i][j] = -1;
//         }
//     }
// }

int main()
{
    int arr[4][4] = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};
    int i, j;
    int n = sizeof(arr)/sizeof(arr[1]);
    int col[n] = {0, 0, 0, 0};
    int row[n] = {0, 0, 0, 0};

//optimal
int col0 = 1;
//int col[m] = {0} ->matrix[0][..]
//int row[n] = {0} -> matrix[..][0]
for(int i = 0; i<n;  i++)
{
    for(int j = 0; j<n; j++)
    {
        if (arr[i][j] == 0) {
        //mark the ith row and 
        arr[i][0] = 0;
        //mark the jth column
        if(j!=0)
        {
            arr[0][j] = 0;
        }
        else
        {
            col0 = 0;
        }
    }
    }
}
for(i = 1; i<n;i++)
{
    for(j = 1; j<n; j++)
    {
        if (arr[i][0] == 0 || arr[0][j] == 0) 
        {
            arr[i][j] = 0;
        }
    }
}
if(arr[0][0]==0)
{
    for(i = 0; i<n; i++)
    {
        arr[0][i] = 0;
    }
}
if(col0==0)
{
    for(i = 0; i<n; i++)
    {
        arr[i][0] = 0;
    }
}
for(i=0; i<n;i++)
{
    for(j = 0; j<n; j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}

// for(i=0; i<4; i++)
// {
//     for(j=0; j<4; j++)
//     {
//         if(arr[i][j]==0)
//         {
//             col[i]=1;
//             row[j]=1;
//         }
//     }
// }
// for(i = 0;i<n; i++)
// {
//     for(j=0; j<n; j++)
//     {
//         if(col[i]==1 || row[j]==1)
//         {
//             arr[i][j]=0;
//         }
//         cout<<arr[i][j]<<" ";
//     }
//     cout<<endl;
// }
//time complexity = O(2*n*m)
//space complexity = O(n)+O(m)
    // for(i=0; i<n; i++)
    // {
    //     for(j = 0; j<n; j++)
    //     {
    //         if(arr[i][j]==0)
    //         {
    //            markCol(arr, j, n);
    //            markRow(arr, i, n);
    //         }
    //     }
    // }
    // for(i=0; i<n; i++)
    // {
    //     for(j = 0; j<n; j++)
    //     {
    //         if(arr[i][j]==-1)
    //         {
    //             arr[i][j]=0;
    //         }
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //time complexity = O(N*M)*(N+M)+(N*M)
    //space complexity = O(1)
}
