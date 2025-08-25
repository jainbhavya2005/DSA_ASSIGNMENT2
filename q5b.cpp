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
        else if(i==j) A[n-1+i-1]=x;   // main diag
        else if(j-i==1) A[2*n-1+i-1]=x; // upper diag
    }
    int get(int i,int j) {
        if(i-j==1) return A[i-2];
        else if(i==j) return A[n-1+i-1];
        else if(j-i==1) return A[2*n-1+i-1];
        else return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    TriDiagonal t(4);
    t.set(1,1,2); t.set(2,1,3); t.set(2,2,4);
    t.set(2,3,5); t.set(3,2,6); t.set(3,3,7);
    t.set(3,4,8); t.set(4,3,9); t.set(4,4,10);
    t.display();
}
