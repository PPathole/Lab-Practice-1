#include<iostream>
#include<omp.h>
#include<time.h>
using namespace std;
#define n 10

int main(){
	double arr[n], min_val = 100.0;
	int i;

	for(i=0; i<n; i++){
		arr[i] = 2.0 + i;
	}

	#pragma omp parallel for reduction(min:min_val)
	for(i=0; i<n; i++){
		if(arr[i] < min_val){
			min_val = arr[i];
		}
	}

	cout<<"The minimum Value is: "<<min_val;
	return 0;
}