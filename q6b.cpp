#include <iostream>
using namespace std;

#define MAX 100  

class SparseMatrix {
    int mat[MAX][3];  
    int terms;

public:
    void read() {
        cout << "Enter rows, cols, non-zero terms: ";
        cin >> mat[0][0] >> mat[0][1] >> mat[0][2];
        terms = mat[0][2];

        cout << "Enter row, col, value for non-zero elements:\n";
        for (int i = 1; i <= terms; i++) {
            cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
        }
    }

    void display() {
        cout << "Row Col Val\n";
        for (int i = 0; i <= terms; i++) {
            cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << "\n";
        }
    }

    void add(SparseMatrix B) {
        if (mat[0][0] != B.mat[0][0] || mat[0][1] != B.mat[0][1]) {
            cout << "Matrices dimensions don’t match!\n";
            return;
        }

        int sum[MAX][3];
        sum[0][0] = mat[0][0];
        sum[0][1] = mat[0][1];
        int i = 1, j = 1, k = 1;

        while (i <= mat[0][2] && j <= B.mat[0][2]) {
            if (mat[i][0] < B.mat[j][0] || 
               (mat[i][0] == B.mat[j][0] && mat[i][1] < B.mat[j][1])) {
                sum[k][0] = mat[i][0];
                sum[k][1] = mat[i][1];
                sum[k][2] = mat[i][2];
                i++; k++;
            } else if (B.mat[j][0] < mat[i][0] || 
                      (B.mat[j][0] == mat[i][0] && B.mat[j][1] < mat[i][1])) {
                sum[k][0] = B.mat[j][0];
                sum[k][1] = B.mat[j][1];
                sum[k][2] = B.mat[j][2];
                j++; k++;
            } else {
                int val = mat[i][2] + B.mat[j][2];
                if (val != 0) {
                    sum[k][0] = mat[i][0];
                    sum[k][1] = mat[i][1];
                    sum[k][2] = val;
                    k++;
                }
                i++; j++;
            }
        }

        while (i <= mat[0][2]) {
            sum[k][0] = mat[i][0];
            sum[k][1] = mat[i][1];
            sum[k][2] = mat[i][2];
            i++; k++;
        }

        while (j <= B.mat[0][2]) {
            sum[k][0] = B.mat[j][0];
            sum[k][1] = B.mat[j][1];
            sum[k][2] = B.mat[j][2];
            j++; k++;
        }

        sum[0][2] = k - 1;

        cout << "\nAddition Result:\nRow Col Val\n";
        for (int x = 0; x <= sum[0][2]; x++) {
            cout << sum[x][0] << " " << sum[x][1] << " " << sum[x][2] << "\n";
        }
    }
};

int main() {
    SparseMatrix A, B;
    cout << "Enter first matrix:\n";
    A.read();
    cout << "Enter second matrix:\n";
    B.read();

    cout << "\nMatrix A:\n"; A.display();
    cout << "\nMatrix B:\n"; B.display();

    A.add(B);

    return 0;
}
