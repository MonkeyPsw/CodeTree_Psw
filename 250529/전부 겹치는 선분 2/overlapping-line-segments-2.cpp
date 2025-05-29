#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for (int i = 0; i < n; i++)
    {
        int x1Max = 0, x2Min = 101;
        
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;

            x1Max = max(x1Max, x1[j]);
            x2Min = min(x2Min, x2[j]);
        }

        if (x1Max <= x2Min)
        {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";

    return 0;
}