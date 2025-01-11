#include <iostream>

using namespace std;

int M, D;

/* 이게 더 낫군
// 윤년이 아닐 때 m번째 달의 마지막 날을 반환하는 함수를 작성합니다.
int LastDayNumber(int m) {
    if(m == 2)
        return 28;
    if(m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    
    return 31;
}

// 윤년이 아닐 때 m월 d일이 존재하는지 여부를 확인하는 함수를 작성합니다.
bool JudgeDay(int m, int d) {
    if(m <= 12 && d <= LastDayNumber(m))
        return true;
    
    return false;
}
*/

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