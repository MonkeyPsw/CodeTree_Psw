#include <iostream>
using namespace std;

int main() { // 요즘 서버가 왜이러냐
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << "*";
        for (int j = 0; j < i * 2; j++)
			cout << " ";
        for (int j = 0; j < n - i; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}