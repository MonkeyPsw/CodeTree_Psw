#include <iostream>

using namespace std;

int Y, M, D;

bool IsLeapYear(int y)
{
    if (y % 4 != 0)
        return false;
    if (y % 100 == 0 && y % 400 != 0)
        return false;
    return true;
}

int LastDayNumber(int y, int m)
{
    if (m == 2)
    {
        if (IsLeapYear(y))
            return 29;
        return 28;
    }

    if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    
    return 31;
}

bool JudgeDay(int y, int m, int d) 
{
    if (d <= LastDayNumber(y, m))
        return true;
    
    return false;
}

int JudgeSeason(int m)
{
    if (m >= 3 && m <= 5)
        return 1;
    else if (m >= 6 && m <= 8)
        return 2;
    else if (m >= 9 && m <= 11)
        return 3;
    else
        return 4;
}

int SeasonDay(int y, int m, int d)
{
    if (!JudgeDay(y, m, d))
        return -1;

    return JudgeSeason(m);
}

int main() {
    cin >> Y >> M >> D;

    int date = SeasonDay(Y, M, D);

    switch (date)
    {
        case 1:
            cout << "Spring";
            break;
        case 2:
            cout << "Summer";
            break;
        case 3:
            cout << "Fall";
            break;
        case 4:
            cout << "Winter";
            break; 
        default:
            cout << -1;
    }

    return 0;
}