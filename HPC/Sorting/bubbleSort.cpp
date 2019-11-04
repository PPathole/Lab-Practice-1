#include<iostream>
#include<omp.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

void bubble(int *, int);
void swap(int &, int &);

void bubble(int *a, int n){
	for(int i=0; i<n; i++){
		int first = i % 2;
		#pragma omp parallel for shared(a, first)
		for(int j=first; j<n-1; j+=2){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}
}

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main(){
	int *a, n;
	cout<<"Enter the number of elements: "<<endl;
	cin>>n;
	a = new int[n];
	cout<<"Enter the numbers: "<<endl;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	bubble(a, n);
	cout<<"Sorted array: "<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i];
		cout<<endl;
	}

	return 0;
}