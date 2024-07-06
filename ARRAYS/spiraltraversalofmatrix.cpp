#include<iostream>
using namespace std;
int main()
{
    int n = 6;
    int m = 6;
    int arr[6][6] = {{1, 2, 3 ,4, 5, 6}, {20, 21 ,22, 23, 24, 7}, {19, 32, 33, 34, 25, 8}, {18, 31, 36, 35, 26, 9}, {17, 30, 29, 28, 27, 10}, {16, 15, 14, 13, 12, 11}};
    int left = 0, right = m-1;
    int top = 0, bottom = n-1;
    int ans[n*m];
    int i, j, k=0;
    while(top<=bottom && left<=right)
    {
    //right
        for(i=left; i<=right; i++)
        {
            ans[k]= arr[top][i];
            k++;
        }
        top++;
        for(i = top; i<=bottom; i++)
        {
            ans[k] = arr[i][right];
            k++;
        }
        right--;
        if(top<=bottom){
        for(i=right; i>=left; i--)
        {
            ans[k] = arr[bottom][i];
            k++;
        }
        bottom--;
        }
        if(left<=right){
        for(i = bottom; i>=top; i--)
        {
            ans[k] = arr[i][left];
            k++;
        }
        left++;
        }
    }
    for(i=0; i<n*m ;i++)
    {
        cout<<ans[i]<<" ";
    }

}
