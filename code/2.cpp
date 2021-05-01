#include <iostream>
  
using namespace std;

void Max_heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
  
    if (l < n && arr[l] > arr[largest])
        largest = l;
  
    if (r < n && arr[r] > arr[largest])
        largest = r;
  
    if (largest != i) {
        swap(arr[i], arr[largest]);
  
        Max_heapify(arr, n, largest);
    }
}

void Heapify(int arr[], int n)
{
    int startIdx = (n / 2) - 1;
  
    for (int i = startIdx; i >= 0; i--) {
        Max_heapify(arr, n, i);
    }
}

void Delete(int arr[], int n)
{
	if(n<=0)
	cout<<"Empty Heap\n";
	else
		for(int i=0; i<n; i++)
		{
			arr[i]=arr[i+1];
		}
}


void Display(int arr[], int n)
{
    cout << "Array representation of Heap is:\n";
  
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main()
{
	int arr[20],a,n=1,i;
	cout<<"Enter first element of the Priority Queue :";
	cin>>arr[0];
	while(a!=4)
	{
		cout<<"\nSelect Command:\n1 -> Insert\n2 -> Delete\n3 -> Display\n4 -> Exit\n";
		cin>>a;
		if(a==1)
		{
			cout<<"Insert Element:";
			cin>>i;
			arr[n++] = i;
			Heapify(arr, n);
		}
		if(a==2)
		{
			if(n>0)
				cout<<"Deleted Element is:"<<arr[0]<<"\n";
			Delete(arr, n);
			n--;
			if(n<0)
				n=0;
			Heapify(arr, n);
		}
		if(a==3)
		{
			Display(arr, n);
		}
	}
	
}
