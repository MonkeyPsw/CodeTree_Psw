#include <iostream>
#include <string>

using namespace std;

string S;

int d1[100000]; // 홀수 길이 팰린드롬 반지름
int d2[100000]; // 짝수 길이 팰린드롬 반지름

int main() {
    cin >> S;

    int n = S.size();

    // 홀수 길이 팰린드롬
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = 1;

        if (i <= r) {
            k = min(d1[l + r - i], r - i + 1);
        }

        while (i - k >= 0 && i + k < n && S[i - k] == S[i + k]) {
            k++;
        }

        d1[i] = k;

        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    // 짝수 길이 팰린드롬
    l = 0;
    r = -1;
    for (int i = 0; i < n; i++) {
        int k = 0;

        if (i <= r) {
            k = min(d2[l + r - i + 1], r - i + 1);
        }

        while (i - k - 1 >= 0 && i + k < n && S[i - k - 1] == S[i + k]) {
            k++;
        }

        d2[i] = k;

        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }

    long long answer = 0;

    for (int i = 0; i < n; i++) {
        answer += d1[i];
        answer += d2[i];
    }

    cout << answer;

    return 0;
}