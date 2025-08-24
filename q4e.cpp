#include <iostream>
using namespace std;

int main() {
    char str[100] = "HELLO World 123!";
    
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // convert to lowercase
        }
        i++;
    }
    
    cout << "Lowercase string: " << str;
    return 0;
}
