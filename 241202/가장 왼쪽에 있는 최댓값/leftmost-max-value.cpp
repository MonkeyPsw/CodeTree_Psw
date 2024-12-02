#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[1000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (n > 0)
    {
        int max = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }

        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == max)
            {
                idx = i;
                break;
            }
        }
        
        cout << idx + 1 << " ";

        n = idx;
    }

    return 0;
}