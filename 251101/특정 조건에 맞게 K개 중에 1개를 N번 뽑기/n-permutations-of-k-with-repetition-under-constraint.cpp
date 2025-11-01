#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> ans;

void PrintAns()
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

void Choose(int cur)
{
    if (cur == N + 1)
    {
        PrintAns();
        return;
    }

    for (int i = 1; i <= K; i++)
    {
        if (ans.size() >= 2 && ans.back() == i && ans[ans.size() - 2] == i)
            continue;

        ans.push_back(i);
        Choose(cur + 1);
        ans.pop_back();
    }

    return;
}

int main() {
    cin >> K >> N;

    Choose(1);

    return 0;
}
