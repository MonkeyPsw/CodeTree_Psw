#include <iostream>
#include <set>

using namespace std;

int T;
int k;
char command[100000];
int n[100000];

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        set<int> st;

        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> command[i] >> n[i];
        }

        for (int i = 0; i < k; i++)
        {
            if (command[i] == 'I')
                st.insert(n[i]);
            else if (command[i] == 'D')
            {
                if (n[i] == 1)
                {
                    if (!st.empty())
                        st.erase(*st.rbegin());
                }
                else
                {
                    if (!st.empty())
                        st.erase(*st.begin());
                }
                
            }
        }

        if (st.empty())
            cout << "EMPTY";
        else
            cout << *st.rbegin() << " " << *st.begin();

        cout << endl;
    }


    return 0;
}
