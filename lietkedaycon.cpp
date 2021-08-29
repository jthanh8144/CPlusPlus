#include <iostream>
#include <stdio.h>
using namespace std;

void init(int b[], int k);
void out(int b[], int k);
int islast(int b[], int n, int k);
void gen(int b[], int n, int k);
void method(int b[], int n, int k);
void allSubSet(int b[], int n);

int main(){
	int n, k;
	cout << "n = ";
	cin >> n;
	cout << "k = ";
	cin >> k;
	int b[n+1];
	method(b, n, k);
	//allSubSet(b, n);
	return 0;
}

void init(int b[], int k){
	for (int i = 1; i <= k; i++){
		b[i] = i;
	}
}

void out(int b[], int k){
	for (int i = 1; i <= k; i++) cout << b[i];
	cout << endl; 
}

int islast(int b[], int n, int k){
	for (int i = 1; i <= k; i++)
		if (b[i] != n-k+i) return 0;
	return 1;
}

void gen(int b[], int n, int k){
	int i = k;
	while (b[i] == n-k+i) i--;
	b[i] += 1;
	for (int j = i+1; j <= k; j++) b[j] = b[i] - i + j;
}

void method(int b[], int n, int k){
	init(b, k);
	out(b, k);
	int stop = islast(b, n, k);
	while (stop == 0){
		gen(b, n, k);
		out(b, k);
		stop = islast(b, n, k);
	}
}

void allSubSet(int b[], int n){
	for (int i = 1; i <= n; i++) method(b, n, i);
}
