#include <iostream>
using namespace std;

class Diagonal {
    int *A;  // store only n diagonal elements
    int n;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
        for(int i=0;i<n;i++) A[i]=0;
    }
    void set(int i,int j,int x) {
        if(i==j) A[i-1]=x;
    }
    int get(int i,int j) {
        if(i==j) return A[i-1];
        else return
