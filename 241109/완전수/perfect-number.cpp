#include <iostream>
using namespace std;

int main() {
    int start, end, cnt = 0;
    cin >> start >> end;
    for (int i = start; i <= end; i++)
    {
        int sum = 0;
        for (int j = i - 1; j > 0; j--)
        {
            if (i % j == 0)
                sum += j;
        }
        if (sum == i)
            cnt++;
    }
    cout << cnt;
    return 0;
}