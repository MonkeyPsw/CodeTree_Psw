#include <iostream>
#include <string>

using namespace std;

int n;
string a;
string b;
int ans;
bool IsReverse = true;

int main() {
    cin >> n;
    cin >> a;
    cin >> b;

    for (int i = n - 1; i >= 0; i--)
    {
        if (IsReverse)
        {
            if (a[i] != b[i])
            {
                ans++;

                while (i >= 0 && a[i] != b[i])
                    i--;

                i++;
                
                IsReverse = false;
            }
        }
        else
        {
            if (a[i] == b[i])
            {
                ans++;

                while (i >= 0 && a[i] == b[i])
                    i--;
                
                i++;
                
                IsReverse = true;
            }
        }
    }

    cout << ans;

    return 0;
}
