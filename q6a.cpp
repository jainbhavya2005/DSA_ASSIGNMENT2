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

    void transpose() {
        int trans[MAX][3];
        trans[0][0] = mat[0][1];
        trans[0][1] = mat[0][0];
        trans[0][2] = terms;

        int k = 1;
        for (int col = 0; col < mat[0][1]; col++) {
            for (int i = 1; i <= terms; i++) {
                if (mat[i][1] == col) {
                    trans[k][0] = mat[i][1];
                    trans[k][1] = mat[i][0];
                    trans[k][2] = mat[i][2];
                    k++;
                }
            }
        }

        cout << "\nTranspose:\nRow Col Val\n";
        for (int i = 0; i <= terms; i++) {
            cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2] << "\n";
        }
    }
};

int main() {
    SparseMatrix A;
    A.read();
    cout << "\nOriginal Matrix (Triplet):\n";
    A.display();

    A.transpose();
    return 0;
}