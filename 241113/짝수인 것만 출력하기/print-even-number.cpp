#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[100];
	int new_arr[100], cnt = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            new_arr[cnt] = arr[i];
            cnt++;
        }
    }

    for(int i = 0; i < cnt; i++)
        cout << new_arr[i] << " ";

    return 0;
}