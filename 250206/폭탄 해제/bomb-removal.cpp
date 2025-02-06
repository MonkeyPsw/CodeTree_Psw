#include <iostream>
#include <string>

using namespace std;

string unlock_code;
char wire_color;
int seconds;

class Bomb {
    public :
        string code;
        char color;
        int time;

        Bomb (string code, char color, int time) {
            this->code = code;
            this->color = color;
            this->time = time;
        }
};

int main() {
    cin >> unlock_code >> wire_color >> seconds;

    Bomb bomb = Bomb(unlock_code, wire_color, seconds);

    cout << "code : " << bomb.code << endl;
    cout << "color : " << bomb.color << endl;
    cout << "second : " << bomb.time;

    return 0;
}