#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
	int q;
	int quest, a, b;
    char x, y;

	cin >> s >> q;
	
	for (int i = 0; i < q; i++)
	{
		cin >> quest;
		switch (quest)
		{
			case 1:
				cin >> a >> b;

                char temp;
                temp = s[a - 1];
                s[a - 1] = s[b - 1];
                s[b - 1] = temp;

                cout << s;

				break;
			case 2:
				cin >> x >> y;
				for (int i = 0; i < s.length(); i++)
				{
					if (s[i] == x)
                        s[i] = y;
				}

                cout << s;

				break;
		}
		cout << endl;
	}
    return 0;
}