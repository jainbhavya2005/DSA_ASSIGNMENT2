#include <iostream>
using namespace std;

class TriDiagonal {
    int *A;
    int n;
public:
    TriDiagonal(int n) {
        this->n=n;
        A=new int[3*n-2];
        for(int i=0;i<3*n-2;i++) A[i]=0;
    }
    void set(int i,int j,int x) {
        if(i-j==1) A[i-2]=x;          // lower diag
        else if(i==
