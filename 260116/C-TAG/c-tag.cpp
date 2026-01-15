#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
string A[500];
string B[500];

int ans;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) cin >> B[i];

    
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                unordered_set<string> ustA;
                unordered_set<string> ustB;
                bool isTag = true;

                for (int group = 0; group < n; group++)
                {
                    string tagA = "";

                    tagA += A[group][i];
                    tagA += A[group][j];
                    tagA += A[group][k];

                    ustA.insert(tagA);
                }

                for (int group = 0; group < n; group++)
                {
                    string tagB = "";

                    tagB += B[group][i];
                    tagB += B[group][j];
                    tagB += B[group][k];

                    if (ustA.find(tagB) != ustA.end())
                    {
                        isTag = false;
                        break;
                    }
                    else
                        ustB.insert(tagB);
                }

                if (isTag)
                    ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
