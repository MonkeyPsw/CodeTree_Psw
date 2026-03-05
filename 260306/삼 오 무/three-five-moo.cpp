#include <iostream>

using namespace std;

long long n;
long long ans;

long long Moo(long long num)
{
    return num / 3 + num / 5 - num / 15;
}

int main() {
    cin >> n;

    long long left = 1;
    long long right = n * 2;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        // left + (right - left) / 2 이렇게 쓰면 좋다던데 몰루

        if (mid - Moo(mid) >= n)
        {
            right = mid - 1;
            ans = mid;
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}

/* O(1) 풀이가 있네
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    int pattern[8] = {1,2,4,7,8,11,13,14};

    long long block = (n - 1) / 8;
    long long idx = (n - 1) % 8;

    cout << block * 15 + pattern[idx];
}
*/