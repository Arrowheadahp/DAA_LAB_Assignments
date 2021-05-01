#include<bits/stdc++.h>
using namespace std;

void pusher(vector<int> &vec,int a, int n)
{
	for(int i=1;i<=n;i++)
	vec.push_back(a);
}

void countsort(int arr[],int n,int max)
{
	int count[max+1] = {0};
	int i;
	for(i=0;i<n;i++)
	count[arr[i]]++;
	
	for(i=1;i<=max;i++)
	count[i]+=count[i-1];
	
	vector<int> vec;
	pusher(vec,0,count[0]);
	
	for(i=1;i<=max;i++)
	{
		pusher(vec,i,count[i]-count[i-1]);
	}
	
	for(i=0;i<n;i++)
	arr[i] = vec[i];
}

int main()
{
	int n,max=0;
	cout<<"Enter number of values: ";
	cin>>n;
	
	int arr[n];
	
	cout<<"Enter the values: ";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	for(int i=0;i<n;i++)
	if(arr[i]>max)
	max=arr[i];

	countsort(arr,n,max);
	
	cout<<"Result: "<<endl;
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	
}
