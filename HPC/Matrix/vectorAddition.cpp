#include<iostream>
#include<omp.h>
#include<time.h>
using namespace std;
#define MAX 100

int main(){
	int a[MAX], b[MAX], c[MAX], i, j, k;

	for(i=0; i<MAX; i++){
		a[i] = rand() % 100;
	}

	cout<<"First Vector: "<<endl;
	for(i=0; i<MAX; i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl;

	for(j=0; j<MAX; j++){
		b[j] = rand() % 100;
	}

	cout<<"Second Vector: "<<endl;
	for(j=0; j<MAX; j++){
		cout<<b[j]<<"\t";
	}

	cout<<endl;

	#pragma omp parallel for
	for(k=0; k<MAX; k++){
		c[k] = a[k] + b[k];
	}

	cout<<"The resultant vector: "<<endl;
	for(k=0; k<MAX; k++){
		cout<<c[k]<<"\t";
	}

	return 0;
}