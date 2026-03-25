#include <iostream>
#include <string>

using namespace std;

int N;
string a;
string b;
int ans;

int main() {
    cin >> N;
    cin >> a;
    cin >> b;

    for (int i = 0; i < N; i++)
    {
        if (a[i] != b[i])
        {
            int cnt = 1;

            while (i < N && a[i] != b[i] && cnt < 4)
            {
                i++;
                cnt++;
            }

            ans++;
        }
    }

    cout << ans;

    return 0;
}
