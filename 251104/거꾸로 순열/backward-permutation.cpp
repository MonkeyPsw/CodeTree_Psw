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
    if (!cur)
    {
        PrintAns();
        return;
    }

    for (int i = n; i >= 1; i--)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        ans.push_back(i);

        Choose(cur - 1);

        ans.pop_back();
        visited[i] = false;
    }

    return;
}

int main() {
    cin >> n;

    Choose(n);

    return 0;
}
