#include<iostream>
using namespace std;
//largest element search
//brute force - sort then access last element
int main()
{
	int i;
	int arr[5] = {1, 2,3, 4, 5};
//	int max = arr[0];
//	int smax = arr[0];
	int n = sizeof(arr)/sizeof(arr[1]);
//	for(i = 0; i<n ; i++)
//	{
//		if(arr[i]>max)
//		max = arr[i];
//	}
//	cout<<max;


//second largest- brute force NlogN + N
//sort 
//for(i = n-2; i>=0; i--)
//if(arr[i]!=largest)
// seclargest = arr[i]
//break;

//better - N + N
//for(i = 0; i<n; i++)
//{
//	if(arr[i]>smax&&a[i]!=max)
//	{
//		smax = arr[i];
//	}
//}
//cout<<smax;


//optimal
int largest= arr[0];
int slargest = -1;
for(i = 0; i<n ; i++)
{
	if(arr[i]>largest)
	{
		slargest = largest;
		largest = arr[i];
	}
	else if(arr[i]<largest && arr[i]>slargest)
	{
		slargest = arr[i];
	}
}
cout<<slargest; 

}
