#include <bits/stdc++.h>
using namespace std;

void distinctelements(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool Unique = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                Unique = false;  // duplicate found
                // break;
            }
        }
        if (Unique) count++;
    }
    cout << "The number of unique elements is " << count << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 5, 6,3,2,1,0,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    distinctelements(arr, n);
    return 0;
}
