#include<iostream>
#include<omp.h>
#include<time.h>
using namespace std;
#define n 10

int main(){
	double arr[n], max_val = 0.0;
	int i;

	for(i=0; i<n; i++){
		arr[i] = 2.0 + i;
	}

	#pragma omp parallel for reduction(max:max_val)
	for(i=0; i<n; i++){
		if(arr[i] > max_val){
			max_val = arr[i];
		}
	}

	cout<<"The Max Value is: "<<max_val;
	return 0;
}