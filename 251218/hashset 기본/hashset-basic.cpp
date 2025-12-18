#include <iostream>
#include <unordered_set>

using namespace std;

int n;
string command[100000];
int x[100000];
unordered_set<int> ust;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command[i] >> x[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (command[i] == "add")
            ust.insert(x[i]);
        else if (command[i] == "remove")
            ust.erase(x[i]);
        else
        {
            if (ust.find(x[i]) != ust.end())
                cout << "true";
            else
                cout << "false";
            cout << endl;
        }
    }

    return 0;
}
