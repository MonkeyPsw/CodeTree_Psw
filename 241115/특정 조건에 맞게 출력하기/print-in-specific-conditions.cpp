#include <iostream>

using namespace std;

int main() {
    int arr[100];
	int new_arr[100], cnt = 0;

    for(int i = 0; i < 100; i++)
    {
        cin >> arr[i];

        if (arr[i] == 0)
        {
            cnt = i;
            break;
        }

        if (arr[i] % 2 == 0)
            new_arr[i] = arr[i] / 2;
        else
            new_arr[i] = arr[i] + 3;
    }
    
    for (int i = 0; i < cnt; i++)
        cout << new_arr[i] << " ";

    return 0;
}