#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> ans;

void PrintAns()
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

void Choose(int cur, int start)
{
    if (cur == M + 1)
    {
        PrintAns();
        return;
    }

    for (int i = start; i <= N; i++)
    {
        ans.push_back(i);
        Choose(cur + 1, i + 1);
        ans.pop_back();
    }

    return;
}

int main() {
    cin >> N >> M;

    Choose(1, 1);

    return 0;
}
