#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int a[100000], k[100000];
int parts;
int current_parts[100000];

vector<int> need_by[100001];
int remain_cnt[100000];
int recipe_cnt[100001];
int done_cnt[100001];
bool possible[100001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> k[i];

        remain_cnt[i] = k[i];
        recipe_cnt[a[i]]++;

        for (int j = 0; j < k[i]; j++) {
            int p;
            cin >> p;
            need_by[p].push_back(i);
        }
    }

    cin >> parts;
    for (int i = 0; i < parts; i++) {
        cin >> current_parts[i];
    }

    queue<int> q;

    for (int i = 0; i < parts; i++) {
        if (!possible[current_parts[i]]) {
            possible[current_parts[i]] = true;
            q.push(current_parts[i]);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < need_by[cur].size(); i++) {
            int recipe = need_by[cur][i];

            remain_cnt[recipe]--;

            if (remain_cnt[recipe] == 0) {
                int made = a[recipe];
                done_cnt[made]++;

                if (done_cnt[made] == recipe_cnt[made] && !possible[made]) {
                    possible[made] = true;
                    q.push(made);
                }
            }
        }
    }

    vector<int> answer;

    for (int i = 1; i <= n; i++) {
        if (possible[i]) {
            answer.push_back(i);
        }
    }

    cout << answer.size() << endl;

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}