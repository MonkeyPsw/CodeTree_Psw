#include <iostream>
#include <string>

using namespace std;

string text;
string pattern;

int FindString()
{
    if (text.find(pattern) != string::npos)
        return text.find(pattern);
    return -1;
}

int main() {
    cin >> text;
    cin >> pattern;

    cout << FindString();

    return 0;
}