#include <iostream>
#include <set>

using namespace std;

int n, m;
int arr[100000];
int queries[100000];
set<int> st;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        st.insert(arr[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (st.lower_bound(queries[i]) != st.end())
            cout << *st.lower_bound(queries[i]);
        else
            cout << -1;

        cout << endl;
    }

    return 0;
}
