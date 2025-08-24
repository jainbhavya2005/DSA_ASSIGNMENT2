#include <iostream>
using namespace std;

class SymmetricMatrix {
    int *arr;   // store only n(n+1)/2 elements
    int n;

public:
    SymmetricMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2];
    }

    ~SymmetricMatrix() {
        delete[] arr;
    }

    // set value at (i, j)
    void set(int i, int j, int val) {
        if (i >= j) {  
            int index = i * (i - 1) / 2 + (j - 1);
            arr[index] = val;
        } else {  
            int index = j * (j - 1) / 2 + (i - 1);
            arr[index] = val;
        }
    }

    // get value at (i, j)
    int get(int i, int j) {
        if (i >= j) {
            int index = i * (i - 1) / 2 + (j - 1);
            return arr[index];
        } else {
            int index = j * (j - 1) / 2 + (i - 1);
            return arr[index];
        }
    }

    // display full matrix
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    SymmetricMatrix mat(n);

    cout << "Enter elements of symmetric matrix: \n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val;
            cin >> val;
            mat.set(i, j, val);
        }
    }

    cout << "\nStored Symmetric Matrix:\n";
    mat.display();

    return 0;
}
