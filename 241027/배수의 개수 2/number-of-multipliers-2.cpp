#include <iostream>
using namespace std;

int main() {
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 != 0)
            cnt++;
    }
    cout << cnt;
    return 0;
}