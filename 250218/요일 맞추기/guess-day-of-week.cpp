#include <iostream>

using namespace std;

int m1, d1, m2, d2;
int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string week[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int BetweenDay(int a, int b, int x, int y)
{
    int day1 = 0, day2 = 0;

    for (int i = 1; i < a; i++)
        day1 += num_of_days[i];
    day1 += b;

    for (int i = 1; i < x; i++)
        day2 += num_of_days[i];
    day2 += y;

    return day2 - day1;
}

string AfterWeek(int n)
{
    if (n < 0)
    {
        n *= -1;
        return week[7 - n % 7];
    }
    return week[n % 7];
}

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    int val = BetweenDay(m1, d1, m2, d2);

    cout << AfterWeek(val);

    return 0;
}