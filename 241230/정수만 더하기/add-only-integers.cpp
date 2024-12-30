#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str;
    int sum = 0;

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
		if (str[i] >= '0' && str[i] <= '9')
			sum += (int)str[i] - '0';
    }

    cout << sum;

    return 0;
}