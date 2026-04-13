#include <iostream>
#include <vector>

using namespace std;

int n;
int from[10000];
int to[10000];
int weight[10000];
vector<pair<int, int> > tree[10001];
bool visited[10001];
int farthestNode;
int maxDist;

void DFS(int node, int dist)
{
    visited[node] = true;

        if (dist > maxDist)
            {
                    maxDist = dist;
                            farthestNode = node;
                                }

                                    for (int i = 0; i < tree[node].size(); i++)
                                        {
                                                int next = tree[node][i].first;
                                                        int cost = tree[node][i].second;

                                                                if (!visited[next])
                                                                            DFS(next, dist + cost);
                                                                                }
                                                                                }

                                                                                int main() {
                                                                                    cin >> n;

                                                                                        for (int i = 0; i < n - 1; i++) {
                                                                                                cin >> from[i];
                                                                                                        cin >> to[i];
                                                                                                                cin >> weight[i];
                                                                                                                    }

                                                                                                                        for (int i = 0; i < n - 1; i++)
                                                                                                                            {
                                                                                                                                    tree[from[i]].push_back({to[i], weight[i]});
                                                                                                                                            tree[to[i]].push_back({from[i], weight[i]});
                                                                                                                                                }

                                                                                                                                                    DFS(from[0], 0);

                                                                                                                                                        for (int i = 1; i <= n; i++)
                                                                                                                                                                visited[i] = false;

                                                                                                                                                                    maxDist = 0;
                                                                                                                                                                        DFS(farthestNode, 0);

                                                                                                                                                                            cout << maxDist;

                                                                                                                                                                                return 0;
                                                                                                                                                                                }