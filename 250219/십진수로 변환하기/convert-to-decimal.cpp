#include <iostream>

using namespace std;

char binary[9];

int main() {
    int num = 0;
    cin >> binary;

    for (int i = 0; binary[i] != '\0'; i++)
        num = num * 2 + (binary[i] - '0');
    
    cout << num;

    return 0;
}