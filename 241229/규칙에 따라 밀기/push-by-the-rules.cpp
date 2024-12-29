#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, quest;

    cin >> str >> quest;

    int len = str.length();

    for (int i = 0; i < quest.length(); i++)
    {
		switch (quest[i])
		{
			case 'L':
                str = str.substr(1, len - 1) + str.substr(0, 1);
                break;
            case 'R':
                str = str.substr(len - 1, 1) + str.substr(0, len - 1);
                break;
        }
    }

    cout << str;

    return 0;
}