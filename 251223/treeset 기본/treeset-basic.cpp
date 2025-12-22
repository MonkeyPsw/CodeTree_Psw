#include <iostream>
#include <set>
#include <string>

using namespace std;

int n;
string command[100000];
int x[100000];
set<int> st;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> command[i];
        if (command[i] == "add" || command[i] == "remove" ||
            command[i] == "find" || command[i] == "lower_bound" ||
            command[i] == "upper_bound") {
            cin >> x[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (command[i] == "add")
            st.insert(x[i]);
        else if (command[i] == "remove")
            st.erase(x[i]);
        else if (command[i] == "find")
            cout << (st.find(x[i]) != st.end() ? "true" : "false") << endl;
        else if (command[i] == "lower_bound")
            cout << (st.lower_bound(x[i]) != st.end() ? to_string(*st.lower_bound(x[i])) : "None") << endl;
        else if (command[i] == "upper_bound")
            cout << (st.upper_bound(x[i]) != st.end() ? to_string(*st.upper_bound(x[i])) : "None") << endl;
        else if (command[i] == "largest")
            cout << (st.rbegin() != st.rend() ? to_string(*st.rbegin()) : "None") << endl;
        else
            cout << (st.rbegin() != st.rend() ? to_string(*st.begin()) : "None") << endl;
    }

    return 0;
}
