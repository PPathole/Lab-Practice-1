#include<iostream>
#include<omp.h>
#include<time.h>
using namespace std;
#define n 20

int main(){
    int arr[n], sum=0;
    #pragma omp parallel for 
    for(int i=0; i<n; i++){
        arr[i] = i;
    }
    
    #pragma omp parallel for reduction(+:sum)
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    
    cout<<"Sum: "<<sum;
    return 0;
}
