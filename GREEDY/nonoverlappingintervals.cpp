#include<iostream>
using namespace std;
int main()
{
    int start[] = {1, 2, 3, 1};
    int finish[] = {2, 3, 4, 3};
    int interval[] = {1, 2, 3, 4};
    int seq[] = {0, 0, 0, 0};
    int n = sizeof(start)/sizeof(start[0]);
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(finish[j+1]<finish[j])
            {
                int t = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = t;

                t = start[j];
                start[j] = start[j+1];
                start[j+1] = t;

                t = interval[j];
                interval[j] = interval[j+1];
                interval[j+1] = t;
            }
        }
    }
    int k = 0;
    seq[k] = interval[0];
    k++;
    int f =finish[0];
    for(int i = 1; i<n; i++)
    {
        if(f<=start[i])
        {
            seq[k] = interval[i];
            k++;
            f = finish[i];
        }
    }
    int t = 0;
    for(i = 0; i<n ;i++)
    {
        if(seq[i]!=0)
        {
            t++;
        }
    }
    int nonoverlapping = n - t;
    cout<<nonoverlapping;
}