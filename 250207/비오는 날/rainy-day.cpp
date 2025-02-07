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

/* 입력코드를 아예 안썼네
// Forecast 정보를 나타내는 클래스 선언
class Forecast {
    public:
        string date, day, weather;
        Forecast(string date, string day, string weather) {
            this->date = date;
            this->day = day;
            this->weather = weather;
        }
};

Forecast ans = Forecast("9999-99-99", "", "");
*/


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

    /* 입력코드 안쓸거면 이렇게 했지?
    for(int i = 1; i <= n; i++) {
            string date, day, weather;
            cin >> date >> day >> weather;

            // Forecast 객체를 만들어 줍니다.
            Forecast f = Forecast(date, day, weather);
            if(weather == "Rain")
                // 비가 오는 경우 가장 최근인지 확인하고,
                // 가장 최근일 경우 정답을 업데이트합니다.
                if(ans.date >= f.date)
                    ans = f;
        }

    */

    cout << d[idx].date << " " << d[idx].day << " " << d[idx].weather;

    return 0;
}