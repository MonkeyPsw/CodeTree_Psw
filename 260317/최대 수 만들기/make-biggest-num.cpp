#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string arr[50000];

bool cmp(string a, string b)
{
    if (a + b > b + a)
        return true;

    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++)
        cout << arr[i];

    return 0;
}
