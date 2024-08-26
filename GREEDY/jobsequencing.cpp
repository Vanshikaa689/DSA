#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<int> jobseq(vector<int> job, vector<int> profit, vector<int> deadline)
{
    vector<int> seq = {0, 0, 0, 0, 0, 0};
    int i, j, t, n=6, k=0;
	for(i = 0; i<n-1; i++)
	{
		for(j = 0; j<n-i-1; j++)
		{
			if(profit[j]<profit[j+1])
			{
				t = profit[j];
				profit[j] = profit[j+1];
				profit[j+1] = t;
				
				t = deadline[j];
				deadline[j] = deadline[j+1];
				deadline[j+1] = t;
				
				t = job[j];
				job[j] = job[j+1];
				job[j+1] = t;
			}
		}
	}
    for(i=0;i<n;i++)
	{	
		j = deadline[i] ;//place job closest to it's deadline
		if(seq[j-1]!=0)
		{
			while(seq[j-1]!=0)
			{
				j--;
			}
			if(j<0)
			{
				break;
			}
			else
			{
				seq[j-1] = job[i];
			}
		}
		else
		{
			seq[j-1] = job[i];
		}
	
	}
    return seq;

}
int main()
{
	vector <int> job = {1, 2, 3, 4, 5, 6};
	vector<int> profit= {15, 10, 12, 20, 8, 5};
	vector<int> deadline = {5, 3, 3, 2, 4, 2};
    vector<int> seq = {0, 0, 0, 0, 0, 0};
    seq = jobseq(job, profit, deadline);
    int sum = 0;
	for(int i = 0; i<seq.size(); i++)
	{
		printf("%d\t", seq[i]);
		sum = sum + profit[i];
	}
    cout<<sum;
	return 0;
}