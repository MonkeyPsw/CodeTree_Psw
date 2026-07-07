#include <iostream>
#include <string>

using namespace std;

string input_str;

int p[200005];

int main() {
    cin >> input_str;

    string s = "#";
    for (int i = 0; i < (int)input_str.size(); i++) {
        s += input_str[i];
        s += "#";
    }

    int n = s.size();
    int center = 0;
    int right = 0;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;

        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        }

        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
               s[i - p[i] - 1] == s[i + p[i] + 1]) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        if (answer < p[i]) {
            answer = p[i];
        }
    }

    cout << answer;

    return 0;
}