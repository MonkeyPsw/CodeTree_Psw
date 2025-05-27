#include <iostream>

using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for (int i = 1; i <= 100; i++)
    {
        bool isOverlap = true;

        for (int j = 0; j < n; j++)
        {
            if (i < x1[j] || i > x2[j])
            {
                isOverlap = false;
                break;
            }
        }

        if (isOverlap)
        {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";

    return 0;
}