#include<iostream>
using namespace std;
void generateRow(int row, int *rowArr) {
    long long ans = 1;
    rowArr[0] = 1;  // The first element is always 1

    for (int i = 1; i <= row; i++) {
        ans = ans * (row - i + 1) / i;  // Calculate the next element in the row
        rowArr[i] = ans;
    }
}
int main()
{
    //print an element at given index,
    int n = 11;
    int r = 4;
    long long res = 1;
    int i;
    n = n-1;
    r = r-1;
    for(i=0; i<r; i++)
    {
        res = res*(n-i);//-> 10/1 *9/2 * 8/3 
        res = res/(i+1);
    }
    cout<<res<<"\n";
    //Time complexity = O(r)
    //Space complexity = O(1)


    // //print entire row,
    // int ans = 1;
    // for(i=1; i<n; i++)
    // {
    //     ans = ans*(n-i);
    //     ans = ans/i;
    //     cout<<ans<<" ";
    // }






    //print pascal triangle   
    const int N = 5;  // Dimension of the array
    int triangle[N][N] = {};  // Initialize all elements to 0

    for (int i = 0; i < N; i++) {
        generateRow(i, triangle[i]);  // Generate each row and store it in the triangle
    }

    // Printing the triangle
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
