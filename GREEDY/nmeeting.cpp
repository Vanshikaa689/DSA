//meeting selection 
#include<iostream>
using namespace std;
int main()
{
	int start[] = {1, 0, 1, 4, 2, 5, 3, 4};
	int finish[] ={3, 4, 2, 6, 9, 8, 5, 5};
	int meeting[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int seq[8] = {0,0,0,0,0,0,0,0};
	int n = sizeof(start)/sizeof(start[0]);
	int i, j;
	for (i = 0; i<n-1; i++)
	{
		for(j = 0; j<n-1-i; j++)
		{
			if(finish[j]>finish[j+1])
			{
				int t = finish[j];
				finish[j] = finish[j+1];
				finish[j+1] = t;
			
				t = start[j];
				start[j] = start[j+1];
				start[j+1] = t;
				
				t = meeting[j];
				meeting[j] = meeting[j+1];
				meeting[j+1] = t;
			}
		}
	}
	int k = 0;
	seq[k] = meeting[0];
	k++;
	int f = finish[0];
	for(i= 1; i<n; i++)
	{
		if(start[i]>=f)
		{
			seq[k] = meeting[i];
			f = finish[i];	
			k++;
		}
	}
	for(i = 0; i<n; i++)
	{
		if(seq[i]!=0)
		{
			cout<<seq[i]<<" ";
		}
	}
	return 0;
}