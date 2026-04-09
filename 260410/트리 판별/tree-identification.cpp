#include <iostream>

using namespace std;

int m;
int from[1000], to[1000];
int indegree[10001];
bool exist[10001];
int nodeCount;
int rootCount;

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
                                                        }

                                                            for (int i = 1; i <= 10000; i++)
                                                                {
                                                                        if (!exist[i])
                                                                                    continue;

                                                                                            nodeCount++;

                                                                                                    if (indegree[i] == 0)
                                                                                                                rootCount++;
                                                                                                                        else if (indegree[i] != 1)
                                                                                                                                {
                                                                                                                                            cout << 0;
                                                                                                                                                        return 0;
                                                                                                                                                                }
                                                                                                                                                                    }

                                                                                                                                                                        if (rootCount == 1 && m == nodeCount - 1)
                                                                                                                                                                                cout << 1;
                                                                                                                                                                                    else
                                                                                                                                                                                            cout << 0;

                                                                                                                                                                                                return 0;
                                                                                                                                                                                                }