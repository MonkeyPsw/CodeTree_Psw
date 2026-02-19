#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int N, K;
int candy[100000];
int pos[100000];
pair<int, int> line[100000];
int j, sum, ans;

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> candy[i] >> pos[i];
    }

    for (int i = 0; i < N; i++)
        line[i] = make_pair(pos[i], candy[i]);
    
    sort(line, line + N);

    for (int i = 0; i < N; i++)
    {
        while (j < N && line[j].first - line[i].first <= 2 * K)
        {
            sum += line[j].second;
            j++;
        }

        ans = max(ans, sum);
        
        sum -= line[i].second;
    }

    cout << ans;

    return 0;
}
