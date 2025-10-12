#include <iostream>
using namespace std;

int main() {
    int ans1 = 0, ans2 = 0;

    for (int i = 0; i < 10; i++)
    {
        int num;
        cin >> num;

        if (num % 3 == 0)
            ans1++;
        if (num % 5 == 0)
            ans2++;
    }

    cout << ans1 << " " << ans2;

    return 0;
}