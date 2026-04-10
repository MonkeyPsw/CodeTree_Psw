#include <iostream>
#include <vector>

using namespace std;

int n, m;
int from[1000];
int to[1000];
int weight[1000];
int query_from[1000];
int query_to[1000];

vector<pair<int, int> > tree[1001];
bool visited[1001];
int ans;

void DFS(int node, int target, int dist)
{
    if (node == target)
        {
                ans = dist;
                        return;
                            }

                                visited[node] = true;

                                    for (int i = 0; i < tree[node].size(); i++)
                                        {
                                                int next = tree[node][i].first;
                                                        int cost = tree[node][i].second;

                                                                if (!visited[next])
                                                                            DFS(next, target, dist + cost);
                                                                                }
                                                                                }

                                                                                int main() {
                                                                                    cin >> n >> m;

                                                                                        for (int i = 0; i < n - 1; i++) {
                                                                                                cin >> from[i] >> to[i] >> weight[i];
                                                                                                    }

                                                                                                        for (int i = 0; i < m; i++) {
                                                                                                                cin >> query_from[i] >> query_to[i];
                                                                                                                    }

                                                                                                                        for (int i = 0; i < n - 1; i++)
                                                                                                                            {
                                                                                                                                    tree[from[i]].push_back(make_pair(to[i], weight[i]));
                                                                                                                                            tree[to[i]].push_back(make_pair(from[i], weight[i]));
                                                                                                                                                }

                                                                                                                                                    for (int i = 0; i < m; i++)
                                                                                                                                                        {
                                                                                                                                                                for (int j = 1; j <= n; j++)
                                                                                                                                                                            visited[j] = false;

                                                                                                                                                                                    ans = 0;
                                                                                                                                                                                            DFS(query_from[i], query_to[i], 0);

                                                                                                                                                                                                    cout << ans << endl;
                                                                                                                                                                                                        }

                                                                                                                                                                                                            return 0;
                                                                                                                                                                                                            }