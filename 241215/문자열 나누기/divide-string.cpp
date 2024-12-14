#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string str[10], total = "";

    cin >> n;

    int length = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        total += str[i];
        length += str[i].length();
    }
    
    int cnt = 1;

    for (int i = 0; i < length; i++)
    {
        cout << total[i];
        if (cnt++ % 5 == 0)
            cout << endl;
    }
    
    return 0;
}