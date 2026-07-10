#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
char c;
string S;

int d1[300000];
int d2[300000];

int getLongestPalindrome(int L, int R) {
    int ret = 0;

    int l = L, r = L - 1;

    // 홀수 길이 팰린드롬
    for (int i = L; i <= R; i++) {
        int k = 1;

        if (i <= r) {
            k = min(d1[l + r - i], r - i + 1);
        }

        while (i - k >= L && i + k <= R && S[i - k] == S[i + k]) {
            k++;
        }

        d1[i] = k;
        ret = max(ret, 2 * k - 1);

        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    l = L;
    r = L - 1;

    // 짝수 길이 팰린드롬
    for (int i = L; i <= R; i++) {
        int k = 0;

        if (i <= r) {
            k = min(d2[l + r - i + 1], r - i + 1);
        }

        while (i - k - 1 >= L && i + k <= R && S[i - k - 1] == S[i + k]) {
            k++;
        }

        d2[i] = k;
        ret = max(ret, 2 * k);

        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }

    return ret;
}

int main() {
    cin >> n >> c;
    cin >> S;

    int answer = 0;
    int start = 0;

    for (int i = 0; i <= n; i++) {
        if (i == n || S[i] == c) {
            if (start <= i - 1) {
                answer = max(answer, getLongestPalindrome(start, i - 1));
            }

            start = i + 1;
        }
    }

    cout << answer;

    return 0;
}