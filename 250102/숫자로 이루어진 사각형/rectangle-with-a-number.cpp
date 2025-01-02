#include <iostream>

using namespace std;

int N;

void PrintRect(int n)
{
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cnt > 9) cnt -= 9;
            cout << cnt++ << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> N;

    PrintRect(N);

    return 0;
}