#include <iostream>
#include <vector>

using namespace std;

int n;
bool visited[9];
vector<int> ans;

void PrintAns()
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

void Choose(int cur)
{
    if (cur == n + 1)
    {
        PrintAns();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        ans.push_back(i);

        Choose(cur + 1);

        ans.pop_back();
        visited[i] = false;
    }

    return;
}

int main() {
    cin >> n;

    Choose(1);

    return 0;
}
