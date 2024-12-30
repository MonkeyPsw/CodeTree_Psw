#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, num, sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
    }

    string sum_str = to_string(sum);

    sum_str = sum_str.substr(1, sum_str.length() - 1) + sum_str.substr(0, 1);

    cout << sum_str;

    return 0;
}