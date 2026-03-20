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
            ans++;
        
        while (i < N && a[i] != b[i])
            i++;
    }

    cout << ans;

    return 0;
}
