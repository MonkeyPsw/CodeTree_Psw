#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int A[20];
vector<int> arr;
int ans;

int CalNum()
{
    int num = arr[0];

    for (int i = 1; i < m; i++)
        num ^= arr[i];
    
    return num;
}

void Choose(int cur, int start)
{
    if (cur == m + 1)
    {
        ans = max(ans, CalNum());
        return;
    }

    for (int i = start; i < n; i++)
    {
        arr.push_back(A[i]);
        Choose(cur + 1, i + 1);
        arr.pop_back();
    }

    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    Choose(1, 0);

    cout << ans;

    return 0;
}