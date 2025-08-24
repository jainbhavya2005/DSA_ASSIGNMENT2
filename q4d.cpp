#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    
    char str[10][50];  // max 10 strings, each up to 50 chars
    
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    
    // Bubble Sort by strcmp-like comparison
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            int k = 0;
            while (str[j][k] == str[j+1][k] && str[j][k] != '\0') k++;
            
            if (str[j][k] > str[j+1][k]) {
                char temp[50];
                int t = 0;
                while ((temp[t] = str[j][t]) != '\0') t++;
                
                t = 0; while ((str[j][t] = str[j+1][t]) != '\0') t++;
                t = 0; while ((str[j+1][t] = temp[t]) != '\0') t++;
            }
        }
    }
    
    cout << "Sorted strings:\n";
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
    return 0;
}
