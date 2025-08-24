#include <iostream>
using namespace std;

int main() {
    char str1[100] = "Hello ";
    char str2[50] = "World";
    
    int i = 0, j = 0;
    while (str1[i] != '\0') i++;  // move to end of str1
    
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++; j++;
    }
    str1[i] = '\0';  // null terminate
    
    cout << "Concatenated string: " << str1;
    return 0;
}
