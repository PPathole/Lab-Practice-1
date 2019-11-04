#include<iostream>
#include<omp.h>
#include<time.h>
using namespace std;
#define n 100

int main(){
	float arr[n], sum = 0.0;
	int i;

	#pragma omp parallel
	for(i=0; i<n; i++){
		arr[i] = i+1;
	}

	#pragma omp parallel for reduction(+:sum)
	for(i=0; i<n; i++){
		sum += arr[i];
	}

	cout<<"The total is: "<<sum<<endl;
	cout<<"The average is: "<<(sum/n);
	return 0;
}