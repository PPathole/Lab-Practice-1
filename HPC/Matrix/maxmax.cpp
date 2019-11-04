#include<iostream>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
using namespace std;
#define n 4

int main()
{
    int a[n][n],b[n][n],c[n][n],m;
    float t1;
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            a[row][col]=rand()%5+1;
            b[row][col]=rand()%5+1;
        }
    }

    cout<<"First Matrix:\n";
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            cout<<a[row][col]<<"\t";
        }
        cout<<endl;
    }

    cout<<"\n\nSecond Matrix:\n";
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            cout<<b[row][col]<<"\t";
        }
        cout<<endl;
    }


    #pragma omp parallel for private(row,col)
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            c[row][col]=0;
            for(m=0;m<n;m++)
            {
                    c[row][col]=c[row][col]+a[row][m]*b[m][col];
            }

        }
    }

    cout<<"\n\nOutput Matrix:\n";
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            cout<<c[row][col]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
