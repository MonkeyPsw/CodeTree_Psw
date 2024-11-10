#include <iostream>
using namespace std;

int main() {
    int twoCnt = 0, twoSum = 0;
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            break;
        if (arr[i] % 2 == 0)
        {
            twoSum += arr[i];
            twoCnt++;
        }
    }
    cout << fixed;
    cout.precision(1);
    cout << twoCnt << " " << twoSum;
    return 0;
}