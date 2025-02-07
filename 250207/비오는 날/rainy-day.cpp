#include <iostream>
#include <string>

using namespace std;

int n;
string date[100];
string day[100];
string weather[100];

class Data {
    public :
        string date, day, weather;

        Data(string date, string day, string weather) {
            this->date = date;
            this->day = day;
            this->weather = weather;
        }

        Data() {}
};

int main() {
    Data d[100];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> date[i] >> day[i] >> weather[i];

        d[i] = Data(date[i], day[i], weather[i]);
    }

    int idx = -1;

    for (int i = 0; i < n; i++)
    {
        if (d[i].weather != "Rain")
            continue;
        
        idx = i;
        break;
    }

    for (int i = idx; i < n; i++)
    {
        if (d[i].weather != "Rain")
            continue;
        
        if (d[idx].date > d[i].date)
            idx = i;
    }

    cout << d[idx].date << " " << d[idx].day << " " << d[idx].weather;

    return 0;
}