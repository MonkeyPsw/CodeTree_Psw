#include <iostream>
#include <vector>

using namespace std;

int m;
int from[1000], to[1000];
int indegree[10001];
bool exist[10001];
bool visited[10001];
vector<int> graph[10001];
int nodeCount;
int rootCount;
int root;
int visitedCount;

void DFS(int node)
{
    visited[node] = true;
        visitedCount++;

            for (int i = 0; i < graph[node].size(); i++)
                {
                        int next = graph[node][i];

                                if (!visited[next])
                                            DFS(next);
                                                }
                                                }

                                                int main() {
                                                    cin >> m;
                                                        for (int i = 0; i < m; i++) {
                                                                cin >> from[i] >> to[i];
                                                                    }

                                                                        for (int i = 0; i < m; i++)
                                                                            {
                                                                                    indegree[to[i]]++;
                                                                                            exist[from[i]] = true;
                                                                                                    exist[to[i]] = true;
                                                                                                            graph[from[i]].push_back(to[i]);
                                                                                                                }

                                                                                                                    for (int i = 1; i <= 10000; i++)
                                                                                                                        {
                                                                                                                                if (!exist[i])
                                                                                                                                            continue;

                                                                                                                                                    nodeCount++;

                                                                                                                                                            if (indegree[i] == 0)
                                                                                                                                                                    {
                                                                                                                                                                                rootCount++;
                                                                                                                                                                                            root = i;
                                                                                                                                                                                                    }
                                                                                                                                                                                                            else if (indegree[i] != 1)
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                cout << 0;
                                                                                                                                                                                                                                            return 0;
                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                            if (rootCount != 1 || m != nodeCount - 1)
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                        cout << 0;
                                                                                                                                                                                                                                                                                return 0;
                                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                                        DFS(root);

                                                                                                                                                                                                                                                                                            if (visitedCount == nodeCount)
                                                                                                                                                                                                                                                                                                    cout << 1;
                                                                                                                                                                                                                                                                                                        else
                                                                                                                                                                                                                                                                                                                cout << 0;

                                                                                                                                                                                                                                                                                                                    return 0;
                                                                                                                                                                                                                                                                                                                    }