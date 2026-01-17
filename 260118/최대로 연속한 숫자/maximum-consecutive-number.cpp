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

        //cout << *it << " " << *prev(it) << endl;
        
        /*
        set<int>::iterator it = st.find(nums[i]);

        int left = *prev(it);
        int right = *next(it);

        int tmp = max((right - *it - 1), (*it - left - 1));

        ans = max(ans, tmp);
        */

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
    }

    return 0;
}
