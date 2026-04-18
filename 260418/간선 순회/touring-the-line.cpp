#include <iostream>
#include <vector>

using namespace std;

int n, d;
int from[50000], to[50000], length[50000];
vector<pair<int, int> > tree[50001];

int down_edge[50001];
long long down_len[50001];

int best_edge = -1;
long long best_len;

bool Better(int edge1, long long len1, int edge2, long long len2)
{
    if (edge1 != edge2)
        return edge1 > edge2;
    return len1 < len2;
}

void DFS(int node, int parent)
{
    int first_edge = 0;
    long long first_len = 0;
    int second_edge = 0;
    long long second_len = 0;

    for (int i = 0; i < tree[node].size(); i++)
    {
        int next = tree[node][i].first;
        int cost = tree[node][i].second;

        if (next == parent)
            continue;

        DFS(next, node);

        int cand_edge = down_edge[next] + 1;
        long long cand_len = down_len[next] + cost;

        if (Better(cand_edge, cand_len, first_edge, first_len))
        {
            second_edge = first_edge;
            second_len = first_len;
            first_edge = cand_edge;
            first_len = cand_len;
        }
        else if (Better(cand_edge, cand_len, second_edge, second_len))
        {
            second_edge = cand_edge;
            second_len = cand_len;
        }
    }

    down_edge[node] = first_edge;
    down_len[node] = first_len;

    int total_edge = first_edge + second_edge;
    long long total_len = first_len + second_len;

    if (Better(total_edge, total_len, best_edge, best_len))
    {
        best_edge = total_edge;
        best_len = total_len;
    }
}

int main() {
    cin >> n >> d;

    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i] >> length[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        tree[from[i]].push_back(make_pair(to[i], length[i]));
        tree[to[i]].push_back(make_pair(from[i], length[i]));
    }

    best_len = 0;
    DFS(1, 0);

    cout << (best_len + d - 1) / d;

    return 0;
}