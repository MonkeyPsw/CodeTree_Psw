#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string str;

unordered_map<char, int> map;

int main() {
    cin >> str;

    for (int i = 0; i < str.length(); i++)
        map[str[i]]++;
    
    for (int i = 0; i < str.length(); i++)
    {
        if (map[str[i]] == 1)
        {
            cout << str[i];
            return 0;
        }
    }

    cout << "None";

    return 0;
}
