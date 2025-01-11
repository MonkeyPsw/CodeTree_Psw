#include <iostream>

using namespace std;

int M, D;

// 31일 1, 3, 5, 7, 8, 10, 12
// 30일 4, 6, 9, 11
// 28일 2
bool IsExist(int month, int day)
{
    if (month <= 12)
    {
        if (month == 2)
        {
            if (day <= 28)
                return true;
            else
                return false;
        }

        if (month <= 7)
        {
            if (month % 2 == 0)
            {
                if (day <= 30)
                    return true;
            }
            else
            {
                if (day <= 31)
                    return true;
            }
        }
        else
        {
            if (month % 2 == 0)
            {
                if (day <= 31)
                    return true;
            }
            else
            {
                if (day <= 30)
                    return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> M >> D;

    cout << (IsExist(M, D) ? "Yes" : "No");

    return 0;
}