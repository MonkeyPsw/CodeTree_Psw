#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int q, quest;

    cin >> str >> q;

    int len = str.length();

    for (int i = 0; i < q; i++)
    {
        cin >> quest;
        
		switch (quest)
		{
			case 1:
                str = str.substr(1, len - 1) + str.substr(0, 1);
                break;
            case 2:
                str = str.substr(len - 1, 1) + str.substr(0, len - 1);
                break;
            case 3:
                string str_Rev;
                for (int j = len - 1; j >= 0; j--)
                    str_Rev += str[j];
                str = str_Rev;
                break;
        }
        
        cout << str << endl;
    }

    return 0;
}