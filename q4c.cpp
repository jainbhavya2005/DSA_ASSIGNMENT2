#include <iostream>
using namespace std;

bool isVowel(char ch) {
    ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch; // convert to lowercase
    return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

int main() {
    char str[100] = "Programming is Fun";
    char result[100];
    
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (!isVowel(str[i])) {
            result[j++] = str[i];
        }
        i++;
    }
    result[j] = '\0';
    
    cout << "String without vowels: " << result;
    return 0;
}
