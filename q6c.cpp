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

    void transpose(int trans[MAX][3]) {
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
    }

    void multiply(SparseMatrix B) {
        if (mat[0][1] != B.mat[0][0]) {
            cout << "Invalid multiplication dimensions!\n";
            return;
        }

        int transB[MAX][3];
        B.transpose(transB);

        int result[MAX][3];
        result[0][0] = mat[0][0];
        result[0][1] = B.mat[0][1];
        int k = 1;

        for (int i = 0; i < mat[0][0]; i++) {
            for (int j = 0; j < B.mat[0][1]; j++) {
                int sum = 0;
                for (int p = 1; p <= terms; p++) {
                    if (mat[p][0] == i) {
                        for (int q = 1; q <= transB[0][2]; q++) {
                            if (transB[q][0] == j && mat[p][1] == transB[q][1]) {
                                sum += mat[p][2] * transB[q][2];
                            }
                        }
                    }
                }
                if (sum != 0) {
                    result[k][0] = i;
                    result[k][1] = j;
                    result[k][2] = sum;
                    k++;
                }
            }
        }

        result[0][2] = k - 1;

        cout << "\nMultiplication Result:\nRow Col Val\n";
        for (int x = 0; x <= result[0][2]; x++) {
            cout << result[x][0] << " " << result[x][1] << " " << result[x][2] << "\n";
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

    A.multiply(B);

    return 0;
}
