#include<iostream>
#include<omp.h>
#include<time.h>
using namespace std;
#define m 4
#define n 3

int main(){
	int mat[m][n], vec[n], out[m], row, col;

	for(row=0; row<m; row++){
		for(col=0; col<n; col++){
			mat[row][col] = rand() % 5;
		}
	}

	cout<<"Matrix Generation: "<<endl;
	for(row=0; row<m; row++){
		for(col=0; col<n; col++){
			cout<<mat[row][col]<<"\t";
		}
		cout<<endl;
	}

	for(row=0; row<n; row++){
		vec[row] = rand()%5+1;
	}

	cout<<"Vector Generation: "<<endl;
	for(row=0; row<n; row++){
		cout<<vec[row]<<"\t";
	}

	#pragma omp parallel
	{
		#pragma omp parallel for
		for(row=0; row<m; row++){
			out[row] = 0;
			for(col=0; col<n; col++){
				out[row] = mat[row][col] * vec[col];
			}
		}
	}
	cout<<"The resultant vector: "<<endl;
	for(row=0; row<m; row++){
		cout<<out[row]<<"\t";
	}

	return 0;
}