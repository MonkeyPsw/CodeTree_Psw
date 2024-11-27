#include <iostream>
using namespace std;

int main() {
	bool isSub = false;
    int n1, n2;
	int a[100], b[100];
	cin >> n1 >> n2;

	for (int i = 0; i < n1; i++)
		cin >> a[i];
	for (int i = 0; i < n2; i++)
		cin >> b[i];

	for (int i = 0; i < n1; i++)
	{
		if (isSub)
			break;
			
		if (a[i] == b[0])
		{
			if (i + n2 - 1 <= n1)
			{
				for (int j = 0; j < n2; j++)
				{
					if (a[i + j] != b[j])
					{
						isSub = false;
						break;
					}
					else
						isSub = true;
				}
			}
		}
	}

	cout << (isSub ? "Yes" : "No");

    return 0;
}