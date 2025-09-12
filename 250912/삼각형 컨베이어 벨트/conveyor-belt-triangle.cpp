#include <iostream>

using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++) cin >> r[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    for (int i = 0; i < t; i++)
    {
        int tmpD = d[n - 1];

        for (int i = n - 1; i >= 1; i--)
            d[i] = d[i - 1];
        
        d[0] = r[n - 1];

        for (int i = n - 1; i >= 1; i--)
            r[i] = r[i - 1];
        
        r[0] = l[n - 1];

        for (int i = n - 1; i >= 1; i--)
            l[i] = l[i - 1];
        
        l[0] = tmpD;
    }

    for (int i = 0; i < n; i++)
        cout << l[i] << " ";
    
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << r[i] << " ";

    cout << endl;

    for (int i = 0; i < n; i++)
        cout << d[i] << " ";

    return 0;
}
