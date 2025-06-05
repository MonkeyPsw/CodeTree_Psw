#include <iostream>

using namespace std;

int n;
char c[100];
int s[100];
int ans, a, b;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> s[i];
    }

    for (int i = 0; i < n; i++)
    {
        int before = 0;
        if (a > b)
            before--;
        else if (a < b)
            before++;

        if (c[i] == 'A')
            a += s[i];
        else
            b += s[i];

        int after = 0;
        if (a > b)
            after--;
        else if (a < b)
            after++;
        
        if (before != after)
            ans++;
    }
    
    cout << ans;

    return 0;
}