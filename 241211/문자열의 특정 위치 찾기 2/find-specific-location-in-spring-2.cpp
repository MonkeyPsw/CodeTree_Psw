#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[5] = {"apple", "banana", "grape", "blueberry", "orange"};
    char c;
    int cnt = 0;

    cin >> c;

    for (int i = 0; i < 5; i++)
    {
        if (arr[i][2] == c || arr[i][3] == c)
        {
            cout << arr[i] << endl;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}