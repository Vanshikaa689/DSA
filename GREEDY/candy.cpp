#include<iostream>
using namespace std;
#include<vector>

/*int candy(vector<int> ratings) {
    int n = ratings.size();
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    left[0] = 1;
    for(int i = 1; i<n; i++)
    {
        if(ratings[i]>ratings[i-1])
        {
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = 1;
        }
    }
    right[n-1] = 1;
    for(int i = n-2; i>0; i--)
    {
        if(ratings[i-1]>ratings[i])
        {
           right[i-1] = right[i]+1;
        }
        else{
            right[i-1] = 1;
        }
    }

    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum = sum + max(left[i], right[i]);
    }
    return sum;
}
int main()
{
    vector<int> ratings = {0, 2, 4, 3, 2, 1, 1, 3, 5, 6, 4, 0, 0};

    cout<<candy(ratings);
}
//time complexity = O(3n)
//space complexity = O(2N)
*/
//slope approach
int sum(vector<int> ratings)
{
    int n = ratings.size();
    int sum = 1;
    int i = 1;
    while(i<n)
    {
        if(ratings[i] == ratings[i-1])
        {
            sum = sum+1;
            i = i+1;
            continue;
        }
        int peak = 1;
        while(i <n && ratings[i]>ratings[i-1])
        {
            peak = peak +1;
            sum = sum+peak;
            i = i+1;
        }
        int down = 1;
        while(i<n && ratings[i]<ratings[i-1])
        {
            sum = sum+ down;
            down = down +1;
            i = i+1;
        }
        if(peak<down)
        {
            sum = sum+(down-peak);
        }
    }
        return sum;
}
int main()
{
    vector<int> ratings = {0, 2, 4, 3, 2, 1, 1, 3, 5, 6, 4, 0, 0};

    cout<<sum(ratings);
}
//time complexity  O(N)
// space compelxity O(1)
