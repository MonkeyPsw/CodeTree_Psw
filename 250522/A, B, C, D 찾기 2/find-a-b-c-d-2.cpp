#include <iostream>
#include <algorithm>

using namespace std;

int nums[15];

bool IsRight(int a, int b, int c, int d)
{
    int myNums[15] = {};
    bool arr[15] = {};

    myNums[0] = a;
    myNums[1] = b;
    myNums[2] = c;
    myNums[3] = d;
    myNums[4] = a + b;
    myNums[5] = b + c;
    myNums[6] = c + d;
    myNums[7] = d + a;
    myNums[8] = a + c;
    myNums[9] = b + d;
    myNums[10] = a + b + c;
    myNums[11] = a + b + d;
    myNums[12] = a + c + d;
    myNums[13] = b + c + d;
    myNums[14] = a + b + c + d;

    sort(myNums, myNums + 15);

    for (int i = 0; i < 15; i++)
    {
        if (nums[i] != myNums[i])
            return false;
    }
    
    return true;
}

int main() {
    for (int i = 0; i < 15; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + 15);

    int a = nums[0];

    for (int b = a; b <= 40; b++)
    {
        for (int c = b; c <= 40; c++)
        {
            for (int d = c; d <= 40; d++)
            {
                if (IsRight(a, b, c, d))
                {
                    cout << a << " " << b << " " << c << " " << d;
                    return 0;
                }
            }
        }
    }

    return 0;
}