#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, sum = 0;
    
    cin >> n;

    string n_str = to_string(n);

    for (int i = 0; i < n_str.length(); i++)
        sum += n_str[i] - '0';

    cout << sum;

    return 0;
}