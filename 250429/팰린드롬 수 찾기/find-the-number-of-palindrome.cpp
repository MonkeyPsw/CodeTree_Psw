#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int X, Y;
int ans;

int ReverseNum(int n)
{
    string s = to_string(n);

    reverse(s.begin(), s.end());

    return stoi(s);
}

int main() {
    cin >> X >> Y;

    for (int i = X; i <= Y; i++)
    {
        int tmp = ReverseNum(i);

        if (i == tmp)
            ans++;
    }

    cout << ans;

    return 0;
}