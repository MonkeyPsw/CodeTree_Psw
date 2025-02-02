#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
string t;
string str[100];

int main() {
    cin >> n >> k >> t;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    string arr[100];
    int a = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i].find(t) == 0)
            arr[a++] = str[i];
    }

    sort(arr, arr + a);

    cout << arr[k - 1];

    return 0;
}