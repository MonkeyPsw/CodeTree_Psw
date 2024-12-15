#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr;

	cin >> arr;

	int i = 0;
	int length = 1;
	int cnt = 0;

	while (arr[i] != '\0')
	{
		char c = arr[i];

		if (c == arr[i + 1])
			length++;
		else
		{
			cnt += 2;
			if (length > 9)
				cnt++;
			length = 1;
		}

		i++;
	}

	cout << cnt << endl;

	i = 0;
	length = 1;
	while (arr[i] != '\0')
	{
		char c = arr[i];

		if (c == arr[i + 1])
			length++;
		else
		{
			cout << c << length;
			length = 1;
		}

		i++;
	}

    return 0;
}