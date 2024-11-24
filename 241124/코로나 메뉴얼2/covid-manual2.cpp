#include <iostream>
using namespace std;

int main() {
	char symp[3];
    int tem[3];
	int cnt_Arr[5] = {};

	for (int i = 0; i < 3; i++)
		cin >> symp[i] >> tem[i];

	for (int i = 0; i < 3; i++)
	{
		if (symp[i] == 'Y')
		{
			if (tem[i] >= 37)
				cnt_Arr[1]++;
			else
				cnt_Arr[3]++;
		}
		else
		{
			if (tem[i] >= 37)
				cnt_Arr[2]++;
			else
				cnt_Arr[4]++;
		}
	}

	for (int i = 1; i < 5; i++)
		cout << cnt_Arr[i] << " ";
	if (cnt_Arr[1] >= 2)
		cout << 'E';

	return 0;
}