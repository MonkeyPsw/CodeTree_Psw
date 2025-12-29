#include <iostream>
#include <set>

using namespace std;

int n, k;
int arr[100000];
set<int> st;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        st.insert(arr[i]);
    }

    set<int>::iterator it = st.end();
    it--;

    while (k--)
    {
        cout << *it << " ";
        it--;
    }

    return 0;
}
