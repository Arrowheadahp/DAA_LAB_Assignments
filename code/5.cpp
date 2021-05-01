#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comparet( vector<int> a,vector<int> b){
	float ae = a[0] *1.0/ a[1];
	float be = b[0] *1.0/ b[1];
	return ae > be;
}

float fractionknapsack(int Values[], int Weights[], int kcapacity, int n){
	int i;
	
	vector<vector<int> > E;	
	
	for (i=0; i<n; i++){
		vector<int> vec;
		vec.push_back(Values[i]);
		vec.push_back(Weights[i]);
//		cout << Values[i]<<Weights[i]<< " "<< vec[0]<<vec[1]<<"\n";
		E.push_back(vec);
	}
	
	
	
	sort(E.begin(), E.end(), comparet);
	
	
	
	float vsum = 0;
	float wrem = kcapacity, w, v;
	float p;
	i = 0;
	while (wrem > 0){
		if (i >= n) break; //all objects added to knapsack
		
		v = E[i][0];
		w = E[i][1];
		
		p = wrem/w;
		if (p>1) p=1.0;
		
		wrem -= w;
		vsum  += p*v;
		
		i+=1;
//		cout << vsum << " ";
	}
	return vsum;
}

int main(){
	int n;
	cout << "Enter number of objects: ";
	cin >> n;
	
	int Values[n], Weights[n], i=0;
	
	for (i=0; i<n; i++){
		cout <<"Enter Value and Weight: ";
		cin >> Values[i] >> Weights[i];
	}
	
	

	cout << "Enter knapsack capacity: ";
	int knapsack;
	cin >> knapsack;
	
//	for (i=0; i<12; i++){
	float k =  fractionknapsack(Values, Weights, knapsack, n) ;
	cout << "\nMaximum Value: " << k;
//}
	
	return 0;
}
