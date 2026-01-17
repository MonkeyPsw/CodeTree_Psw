#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
int nums[100000];
set<int> st;
int ans;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }

    st.insert(-1);
    st.insert(n + 1);

    for (int i = 0; i < m; i++)
    {
        st.insert(nums[i]);
        
        set<int>::iterator it = st.find(nums[i]);

        int left = *prev(it) - *it;
        int right = *next(it) - *it;

        int tmp = max((right - 1), (left - 1));

        if (tmp == ans)
            cout << ans << endl;
        else
        {
            it = st.begin();
            it++;

            while (it != st.end())
            {
                tmp = max(tmp, (*it - *prev(it) - 1));
                it++;
            }

            ans = tmp;
            cout << tmp << endl;
        }

        /* 시간초과
        set<int>::iterator it = st.begin();
        it++;

        int tmp = 0;

        while (it != st.end())
        {
            tmp = max(tmp, (*it - *prev(it) - 1));
            it++;
        }

        if (tmp == ans)
            cout << ans << endl;
        else
        {
            cout << tmp << endl;
            ans = tmp;
        }
        */
    }

    return 0;
}
