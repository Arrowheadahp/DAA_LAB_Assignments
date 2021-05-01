#include <iostream>
#include <string>
using namespace std;

int longestcommonsubseq(string a, string b){
	int an = a.length(), bn = b.length();
	int M[an+1][bn+1] = {0};
	
	
	int i, j;
	
	
	for (i=0; i<an+1; i++){
		for (j=0; j<bn+1; j++){
			M[i][j] = 0;
		}
	}
	for (i=1; i<=an; i++){
		for (j=1; j<=bn; j++){
			M[i][j] = max(M[i][j-1], M[i-1][j]) + (a[i]==b[j]);
//			cout << M[i][j]<<"\t";
		}
//		cout <<"\n";
	}
	
	return M[an][bn];
	
}

int main(){
	string a, b;
	
	cout << "Enter words: ";
	
	cin >> a >> b;
	
	cout << "Length of Longest Common Subsequence is " << longestcommonsubseq(a, b);
	
	
	return 0;
}
