#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    int Score[4];
    int Sum[10] = {};

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> Score[j];
            Sum[i] += Score[j];
        }
        if ((double)Sum[i] / 4 >= 60)
        {
            cout << "pass";
            cnt++;
        }
        else
            cout << "fail";
        cout << endl;
    }
    cout << cnt;
    
    return 0;
}