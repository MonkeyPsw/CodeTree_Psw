#include <iostream>

using namespace std;

string A;
string B;
int del[200000];
int ans;

bool IsPossible(int num)
{
    bool delIdx[200000] = {};
    int cur = 0;

    for (int i = 0; i < num; i++)
        delIdx[del[i] - 1] = true;

    for (int i = 0; i < A.length(); i++)
    {
        if (delIdx[i])
            continue;

        if (A[i] == B[cur])
        {
            cur++;

            if (cur == B.length())
                return true;
        }
    }

    return false;
}

int main() {
    cin >> A;
    cin >> B;
    for (int i = 0; i < A.length(); i++) {
        cin >> del[i];
    }

    int left = 0;
    int right = A.length();

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (IsPossible(mid))
        {
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }

    cout << ans + 1;

    return 0;
}
