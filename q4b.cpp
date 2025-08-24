#include <iostream>
using namespace std;

int main() {
    char str[100] = "OpenAI";
    
    int n = 0;
    while (str[n] != '\0') n++;  // find length
    
    int start = 0, end = n - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    
    cout << "Reversed string: " << str;
    return 0;
}
