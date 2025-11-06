#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[10][10];
bool visited[10];
int ans;
vector<int> arr;

void CheckAns()
{
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
        cnt += arr[i];
    
    ans = max(ans, cnt);
}

void Choose(int cur)
{
    if (cur == n)
    {
        CheckAns();
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (visited[j])
            continue;

        visited[j] = true;
        arr.push_back(grid[cur][j]);

        Choose(cur + 1);

        arr.pop_back();
        visited[j] = false;
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
