#include <iostream>
#include <algorithm>

using namespace std;

int N;
int nums[2000];

int main() {
    cin >> N;

    for (int i = 0; i < 2 * N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + 2 * N);

    int min = nums[0] + nums[2 * N - 1];

    for (int i = 1; i < N; i++)
    {
        if (min < nums[i] + nums[2 * N - 1 - i])
            min = nums[i] + nums[2 * N - 1 - i];
    }

    cout << min;

    return 0;
}
