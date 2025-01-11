#include <iostream>

using namespace std;

int n1, n2;
int a[100], b[100];

bool IsSame(int x, int y)
{
    if (x == y)
        return true;
    return false;
}

int main() {
    cin >> n1 >> n2;

    bool isSub = true;

    for (int i = 0; i < n1; i++) cin >> a[i];

    for (int i = 0; i < n2; i++) cin >> b[i];

    for (int i = 0; i < n1 - n2; i++)
    {
        if (IsSame(a[i], b[0]))
        {
            if (isSub)
			    break;

            for (int j = 0; j < n2; j++)
            {
                if (!IsSame(a[i + j], b[j]))
                {
                    isSub = false;
                    break;
                }
                else
                    isSub = true;
            }
        }
    }

    cout << (isSub ? "Yes" : "No");

    return 0;
}