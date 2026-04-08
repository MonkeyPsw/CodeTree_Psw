#include <iostream>

using namespace std;

int n;
int parent[50];
int remove_node;
int ans;

bool IsRemoved(int node)
{
    while (node != -1)
        {
                if (node == remove_node)
                            return true;
                                    node = parent[node];
                                        }

                                            return false;
                                            }

                                            int main() {
                                                cin >> n;
                                                    for (int i = 0; i < n; i++) {
                                                            cin >> parent[i];
                                                                }
                                                                    cin >> remove_node;

                                                                        for (int i = 0; i < n; i++)
                                                                            {
                                                                                    if (IsRemoved(i))
                                                                                                continue;

                                                                                                        bool isLeaf = true;

                                                                                                                for (int j = 0; j < n; j++)
                                                                                                                        {
                                                                                                                                    if (IsRemoved(j))
                                                                                                                                                    continue;

                                                                                                                                                                if (parent[j] == i)
                                                                                                                                                                            {
                                                                                                                                                                                            isLeaf = false;
                                                                                                                                                                                                            break;
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                        if (isLeaf)
                                                                                                                                                                                                                                                    ans++;
                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                            cout << ans;

                                                                                                                                                                                                                                                                return 0;
                                                                                                                                                                                                                                                                }