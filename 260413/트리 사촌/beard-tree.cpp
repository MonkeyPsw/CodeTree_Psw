#include <iostream>

using namespace std;

int n, k;
int sequence[1000];
int parent[1000];
int p, ans;

int main() {
    cin >> n >> k;
        for (int i = 0; i < n; i++) {
                cin >> sequence[i];
                    }

                        int target = -1;

                            for (int i = 0; i < n; i++)
                                {
                                        if (sequence[i] == k)
                                                {
                                                            target = i;
                                                                        break;
                                                                                }
                                                                                    }

                                                                                        parent[0] = -1;

                                                                                            if (n >= 2)
                                                                                                    parent[1] = 0;

                                                                                                        for (int i = 2; i < n; i++)
                                                                                                            {
                                                                                                                    if (sequence[i] != sequence[i - 1] + 1)
                                                                                                                                p++;

                                                                                                                                        parent[i] = p;
                                                                                                                                            }

                                                                                                                                                if (target == 0 || parent[target] == -1 || parent[parent[target]] == -1)
                                                                                                                                                    {
                                                                                                                                                            cout << 0;
                                                                                                                                                                    return 0;
                                                                                                                                                                        }

                                                                                                                                                                            int grand = parent[parent[target]];

                                                                                                                                                                                for (int i = 1; i < n; i++)
                                                                                                                                                                                    {
                                                                                                                                                                                            if (parent[i] != parent[target] &&
                                                                                                                                                                                                        parent[i] != -1 &&
                                                                                                                                                                                                                    parent[parent[i]] == grand)
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                        ans++;
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                        cout << ans;

                                                                                                                                                                                                                                                            return 0;
                                                                                                                                                                                                                                                            }