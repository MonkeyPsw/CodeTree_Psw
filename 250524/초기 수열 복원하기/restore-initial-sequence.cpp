#include <iostream>

using namespace std;

int n;
int adjacent[1000];

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> adjacent[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int oriNum[1001] = {};
        bool usedNum[1001] = {};
        bool isDone = true;

        oriNum[0] = i;
        usedNum[i] = true;

        for (int j = 0; j < n - 1; j++)
        {
            int nextOriNum = adjacent[j] - oriNum[j];

            if (nextOriNum == 0 || usedNum[nextOriNum])
            {
                isDone = false;
                break;
            }

            oriNum[j + 1] = nextOriNum;
            usedNum[oriNum[j + 1]] = true;
        }

        if (isDone)
        {
            for (int i = 0; i < n; i++)
                cout << oriNum[i] << " ";
            
            break;
        }
    }

    return 0;
}