#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int weight;
};

struct Group {
    long long first;
    long long second;
    int cnt;
};

int n;
int from[100000], to[100000], weight[100000];

vector<Edge> tree[100001];
int parentNode[100001];
int order[100001];
int orderCnt;

long long down1[100001];
long long down2[100001];
int downCnt[100001];

long long ans1 = -1;
long long ans2 = -1;

bool cmp(Group a, Group b)
{
    return a.first > b.first;
}

void UpdateAnswer(long long value)
{
    if (value == -1)
        return;

    if (value > ans1)
    {
        ans2 = ans1;
        ans1 = value;
    }
    else if (value > ans2)
        ans2 = value;
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

    vector<int> stack;
    stack.push_back(1);
    parentNode[1] = -1;

    while (!stack.empty())
    {
        int node = stack.back();
        stack.pop_back();

        order[orderCnt++] = node;

        for (int i = 0; i < tree[node].size(); i++)
        {
            int next = tree[node][i].to;

            if (next == parentNode[node])
                continue;

            parentNode[next] = node;
            stack.push_back(next);
        }
    }

    for (int idx = orderCnt - 1; idx >= 0; idx--)
    {
        int node = order[idx];

        vector<Group> groups;
        groups.push_back({0, -1, 1});

        for (int i = 0; i < tree[node].size(); i++)
        {
            int next = tree[node][i].to;
            int cost = tree[node][i].weight;

            if (next == parentNode[node])
                continue;

            long long firstLen = down1[next] + cost;
            long long secondLen = -1;

            if (down2[next] != -1)
                secondLen = down2[next] + cost;

            groups.push_back({firstLen, secondLen, downCnt[next]});
        }

        sort(groups.begin(), groups.end(), cmp);

        down1[node] = groups[0].first;
        down2[node] = -1;
        downCnt[node] = 0;

        for (int i = 0; i < groups.size(); i++)
        {
            if (groups[i].first == down1[node])
                downCnt[node] = min(2, downCnt[node] + groups[i].cnt);
            else
                down2[node] = max(down2[node], groups[i].first);

            if (groups[i].second != -1)
                down2[node] = max(down2[node], groups[i].second);
        }

        if (groups.size() >= 2)
        {
            long long best = groups[0].first + groups[1].first;
            long long secondBest = -1;

            bool duplicated = false;

            if (groups[0].first == groups[1].first)
            {
                int cnt = 0;
                while (cnt < groups.size() && groups[cnt].first == groups[0].first)
                    cnt++;

                if (cnt >= 3)
                    duplicated = true;
                else if ((long long)groups[0].cnt * groups[1].cnt >= 2)
                    duplicated = true;
            }
            else
            {
                int cnt = 1;
                while (cnt < groups.size() && groups[cnt].first == groups[1].first)
                    cnt++;

                if (cnt - 1 >= 2)
                    duplicated = true;
                else if ((long long)groups[0].cnt * groups[1].cnt >= 2)
                    duplicated = true;
            }

            if (duplicated)
                secondBest = best;
            else
            {
                if (groups[0].second != -1)
                    secondBest = max(secondBest, groups[0].second + groups[1].first);

                if (groups[1].second != -1)
                    secondBest = max(secondBest, groups[0].first + groups[1].second);

                if (groups.size() >= 3)
                    secondBest = max(secondBest, groups[0].first + groups[2].first);
            }

            UpdateAnswer(best);
            UpdateAnswer(secondBest);
        }
    }

    cout << ans2;

    return 0;
}