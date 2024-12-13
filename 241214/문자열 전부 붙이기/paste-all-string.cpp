#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string str, total = "";

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        total += str;
    }
    cout << total;
    
    return 0;
}