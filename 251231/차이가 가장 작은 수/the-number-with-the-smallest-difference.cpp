#include <iostream>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int arr[100000];
set<int> st;
int ans = INT_MAX;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        st.insert(arr[i]);
    }

    set<int>::iterator it;
    for (it = st.begin(); it != st.end(); it++)
    {
        if (st.lower_bound(*it + m) != st.end())
            ans = min(ans, *st.lower_bound(*it + m) - *it);
    }

    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}
