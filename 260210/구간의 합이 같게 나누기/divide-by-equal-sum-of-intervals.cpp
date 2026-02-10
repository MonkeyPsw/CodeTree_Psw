#include <iostream>

using namespace std;

int n;
long long arr[100000];
long long arrSum[100000];
long long targetL[100000], targetR[100000];
long long sum, target;
int cnt, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        sum += arr[i];
    }

    target = sum / 4;

    arrSum[0] = arr[0];
    for (int i = 1; i < n; i ++)
        arrSum[i] = arrSum[i - 1] + arr[i];

    /*
    for (int i = 0; i < n; i++)
        cout << arrSum[i] << " ";
    cout << endl;
    */

    for (int i = 0; i < n - 2; i++)
    {
        if (arrSum[i] == 2 * target)
            targetL[i] = cnt;

        if (arrSum[i] == target)
            cnt++;
    }

    cnt = 0;
    for (int i = n - 1; i >= 2; i--)
    {
        targetR[i] = cnt;

        if (arrSum[i] == 3 * target)
            cnt++;
    }

    /*
    for (int i = 0; i < n; i++)
        cout << targetL[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << targetR[i] << " ";
    */

    for (int i = 2; i < n - 2; i++)
        ans += targetL[i] * targetR[i];

    cout << ans;
    
    return 0;
}
