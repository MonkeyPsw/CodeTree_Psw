#include <iostream>

using namespace std;

int m1, m2, d1, d2;
string A;
int num_of_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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

    return day2 - day1 + 1;
}

int FindIndex(string s)
{
    for (int i = 0; i < 7; i++) 
        if (week[i] == s)
            return i;
}

int AfterWeek(int n, string s)
{
    int cnt = 0;

    if (n > 7)
        cnt += n / 7;
    
    if (n % 7 >= FindIndex(s))
        cnt++;

    return cnt;
}

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> A;

    int val = BetweenDay(m1, d1, m2, d2);

    cout << AfterWeek(val, A);

    return 0;
}