#include <iostream>
using namespace std;

double fibonacciexpo(int n){ // Exponential algorithm
	if (n==1 || n==0){
		return n;
	}
	return fibonacciexpo(n-1) + fibonacciexpo(n-2);
}

double Fib[1000000];
double fibonaccilinear(int n){
	if (n==1 || n==0){
		return n;
	}
	if (Fib[n] != 0){
		return Fib[n];
	}
	Fib[n] = fibonaccilinear(n-1) + fibonaccilinear(n -2);
	return Fib[n];
}

int main(){
	
	int i;
	cout << "Exponential Implementation: \n";
	for (i=1; i<15; i++){
		cout << fibonacciexpo(i) << " ";
	}
	cout << "\n";
	
	cout << "\nLineal Implementation: \n";
	for (i=1; i<15; i++){
		cout << fibonaccilinear(i) << " ";
	}
	cout << "\n";
	
	
	return 0;
}
