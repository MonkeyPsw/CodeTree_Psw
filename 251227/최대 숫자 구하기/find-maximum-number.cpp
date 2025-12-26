#include <iostream>
#include <set>

using namespace std;

int n, m;
int queries[100000];
set<int> st;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
    }

    for (int i = 1; i <= m; i++)
        st.insert(i);

    for (int i = 0; i < n; i++)
    {
        st.erase(queries[i]);
        
        cout << *st.rbegin() << endl;
    }

    return 0;
}
