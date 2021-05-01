#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cout<<"Enter limit: ";
    cin>>n;
    int arr[n];
    cout<<"Enter values: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    cout<<"Enter value of k: ";
    cin>>k;

    int max = 0;
    for(int i=0;i<n;i++)
    if(arr[i]>max)
    max=arr[i];

    int count[max+1]={0};
    for(int i=0;i<n;i++)
    count[arr[i]]++;

    int sum=0,res;
    for(int i=0;i<=max;i++)
    {
        sum+=count[i];
        if(sum>=k)
        {
            res=i;
            break;
        }
    }
    cout<<"kth smallest element is: "<<res<<endl;
    return 0;
}
