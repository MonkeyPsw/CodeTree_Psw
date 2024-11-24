#include <iostream>
using namespace std;

int main() {
	int n, q;
	int quest, a, b, s, e;
    int arr[100];
	cin >> n >> q;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < q; i++)
	{
		int idx = -1;
		cin >> quest;
		switch (quest)
		{
			case 1:
				cin >> a;
				cout << arr[a - 1];
				break;
			case 2:
				cin >> b;
				for (int i = 0; i < n; i++)
				{
					if (arr[i] == b)
					{
						idx = i;
						break;
					}
				}
				if (idx == -1)
					cout << 0;
				else
					cout << ++idx;
				break;
			case 3:
				cin >> s >> e;
				for (int i = s - 1; i < e; i++)
					cout << arr[i] << " ";
				break;
		}
		cout << endl;
	}
    return 0;
}