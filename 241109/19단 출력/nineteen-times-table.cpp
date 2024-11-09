#include <iostream>
using namespace std;

int main() {
    int cnt = 0;
    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            if (j == 19) cnt++;
            
            cout << i << " * " << j << " = " << i * j;

            if (cnt++ % 2 != 0)
                cout << endl;
            else
                cout << " / ";
        }
    }
    return 0;
}