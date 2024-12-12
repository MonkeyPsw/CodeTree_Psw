#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string arr[20];
    char c;
    
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> c;

    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == c)
        {
            cnt++;
            sum += arr[i].length();
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << cnt << " " << (double)sum / cnt;

    return 0;
}