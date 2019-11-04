#include<iostream>
#include<omp.h>
#include<time.h>
using namespace std;
#define n 10

int main(){
	int a[n], b[n], i, sum=0;

	for(i=0; i<n; i++){
		a[i] = rand() % 10;
	}

	for(i=0; i<n; i++){
		b[i] = rand() % 10;
	}

	#pragma omp parallel for reduction(+:sum)
	for(i=0; i<n; i++){
		sum = sum + (a[i] * b[i]);
	}

	cout<<"The sum is: "<<sum;
	return 0;
}