#include <iostream>
#include <string>

using namespace std;

string secret_code;
char meeting_point;
int secret_time;

class Secret {
    public:
        string code;
        char point;
        int tm;

        Secret(string code, char point, int t) {
            this->code = code;
            this->point = point;
            this->tm = t;
        }
};


int main() {
    cin >> secret_code >> meeting_point >> secret_time;

    Secret s = Secret(secret_code, meeting_point, secret_time);

    cout << "secret code : " << s.code << endl;
    cout << "meeting point : " << s.point << endl;
    cout << "time : " << s.tm;

    return 0;
}