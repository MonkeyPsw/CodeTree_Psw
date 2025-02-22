#include <iostream>

using namespace std;

int n;
int x1[100], x2[100];
int line[101];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        
        for (int j = x1[i]; j <= x2[i]; j++)
            line[j]++;
    }

    int max = line[1];
    for (int i = 1; i <= 100; i++)
    {
        if (max < line[i])
            max = line[i];
    }

    cout << max;

    return 0;
}