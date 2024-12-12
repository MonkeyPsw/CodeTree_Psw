#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr;

	cin >> arr;

	for (int i = 0; arr[i] != '\0'; i++)
		cout << arr[i] << endl;

    return 0;
}