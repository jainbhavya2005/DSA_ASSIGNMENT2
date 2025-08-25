#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int diagonal[4] = {5, 8, 3, 6};  // directly store diagonal elements

    // Display the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << diagonal[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }

    return 0;
}
