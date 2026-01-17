#include <iostream>
#include <set>
#include <utility>

using namespace std;

int n, m;
int nums[100000];
set<int> st; // 제거숫자
set<pair<int, int> > length; // 길이, 오른쪽끝

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }

    // 길이 계산용
    st.insert(-1);
    st.insert(n + 1);

    for (int i = 0; i < m; i++)
    {
        st.insert(nums[i]);

        set<int>::iterator it = st.find(nums[i]);

        int leftNum = *prev(it);
        int rightNum = *next(it);

        if (length.find(make_pair(rightNum - leftNum - 1, rightNum)) != length.end())
            length.erase(make_pair(rightNum - leftNum - 1, rightNum));

        length.insert(make_pair(nums[i] - leftNum - 1, nums[i]));
        length.insert(make_pair(rightNum - nums[i] - 1, rightNum));

        cout << length.rbegin()->first << endl;


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
