#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;

int main() {
    cin >> str;

    int n = str.size();
    int answer = 1;

    for (int center = 0; center < n; center++) {
        int left = center;
        int right = center;

        while (left >= 0 && right < n && str[left] == str[right]) {
            answer = max(answer, right - left + 1);
            left--;
            right++;
        }

        left = center;
        right = center + 1;

        while (left >= 0 && right < n && str[left] == str[right]) {
            answer = max(answer, right - left + 1);
            left--;
            right++;
        }
    }

    cout << answer;

    return 0;
}