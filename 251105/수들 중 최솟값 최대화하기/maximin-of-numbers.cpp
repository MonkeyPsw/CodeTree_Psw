#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[10][10];
bool visitedX[10], visitedY[10];
int ans;
vector<int> arr;

void CheckAns()
{
    int cnt = 10001;

    for (int i = 0; i < arr.size(); i++)
        cnt = min(cnt, arr[i]);
    
    ans = max(ans, cnt);
}

void Choose(int cur)
{
    if (cur == n)
    {
        CheckAns();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visitedX[i] || visitedY[j])
                continue;

            visitedX[i] = true;
            visitedY[j] = true;
            arr.push_back(grid[i][j]);

            Choose(cur + 1);

            arr.pop_back();
            visitedX[i] = false;
            visitedY[j] = false;
        }
    }

    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Choose(0);

    cout << ans;

    return 0;
}
