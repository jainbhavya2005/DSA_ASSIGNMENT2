#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) 
            return i; // return index if found
    }
    return -1; // not found
}

// Binary Search (on sorted array)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) 
            return mid; // found
        else if (arr[mid] < key) 
            low = mid + 1;  // search right half
        else 
            high = mid - 1; // search left half
    }
    return -1; // not found
}

int main() {
    // Sorted array for binary search
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 40;

    cout << "Using Linear Search: ";
    int index1 = linearSearch(arr, n, key);
    if (index1 != -1) cout << "Element found at index " << index1 << endl;
    else cout << "Element not found" << endl;

    cout << "Using Binary Search: ";
    int index2 = binarySearch(arr, n, key);
    if (index2 != -1) cout << "Element found at index " << index2 << endl;
    else cout << "Element not found" << endl;

    return 0;
}
