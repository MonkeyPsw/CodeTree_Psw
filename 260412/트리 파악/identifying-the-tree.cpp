#include <iostream>
#include <vector>

using namespace std;

int n;
int from[100000], to[100000];
vector<int> tree[100001];
bool visited[100001];
int sumDepth;

void DFS(int node, int depth)
{
    visited[node] = true;

        bool isLeaf = true;

            for (int i = 0; i < tree[node].size(); i++)
                {
                        int next = tree[node][i];

                                if (!visited[next])
                                        {
                                                    isLeaf = false;
                                                                DFS(next, depth + 1);
                                                                        }
                                                                            }

                                                                                if (isLeaf)
                                                                                        sumDepth += depth;
                                                                                        }

                                                                                        int main() {
                                                                                            cin >> n;
                                                                                                for (int i = 0; i < n - 1; i++) {
                                                                                                        cin >> from[i] >> to[i];
                                                                                                            }

                                                                                                                for (int i = 0; i < n - 1; i++)
                                                                                                                    {
                                                                                                                            tree[from[i]].push_back(to[i]);
                                                                                                                                    tree[to[i]].push_back(from[i]);
                                                                                                                                        }

                                                                                                                                            DFS(1, 0);

                                                                                                                                                if (sumDepth % 2 == 1)
                                                                                                                                                        cout << 1;
                                                                                                                                                            else
                                                                                                                                                                    cout << 0;

                                                                                                                                                                        return 0;
                                                                                                                                                                        }