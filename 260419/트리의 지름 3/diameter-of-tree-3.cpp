#include <iostream>
#include <vector>

using namespace std;

int n;
int from[100000], to[100000], weight[100000];
vector<pair<int, int> > tree[100001];

long long down[100001];
long long ans1 = 0;
long long ans2 = 0;

void Update(long long val)
{
    if (val > ans1)
    {
        ans2 = ans1;
        ans1 = val;
    }
    else if (val > ans2)
    {
        ans2 = val;
    }
}

long long DFS(int node, int parent)
{
    long long max1 = 0;
    long long max2 = 0;

    for (int i = 0; i < tree[node].size(); i++)
    {
        int next = tree[node][i].first;
        int cost = tree[node][i].second;

        if (next == parent)
            continue;

        long long val = DFS(next, node) + cost;

        if (val > max1)
        {
            max2 = max1;
            max1 = val;
        }
        else if (val > max2)
        {
            max2 = val;
        }
    }

    Update(max1);
    Update(max1 + max2);

    return max1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i] >> weight[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        tree[from[i]].push_back({to[i], weight[i]});
        tree[to[i]].push_back({from[i], weight[i]});
    }

    DFS(1, 0);

    cout << ans2;

    return 0;
}