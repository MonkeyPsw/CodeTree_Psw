#include <iostream>
#include <set>

using namespace std;

int n, m;
int a[100000];
set<int> st;
int cnt;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++)
        st.insert(i);
    
    for (int i = 0; i < n; i++)
    {
        /* 바로 --보단 그냥 시작점인지 검사하는게 낫겠네
        set<int>::iterator it = st.upper_bound(a[i]);
        it--;

        if (*it <= a[i])
        {
            st.erase(it);
            cnt++;
        }
        else
            break;
        */

        set<int>::iterator it = st.upper_bound(a[i]);

        if (it != st.begin())
        {
            st.erase(--it);
            cnt++;
        }
        else
            break;
    }

    cout << cnt;

    return 0;
}
