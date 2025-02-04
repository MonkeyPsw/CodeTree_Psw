#include <iostream>
#include <string>

using namespace std;

string user2_id;
int user2_level;

class User {
    public :
        string id;
        int level;

        User(string id = "codetree", int level = 10) {
            this->id = id;
            this->level = level;
        }
};

int main() {
    cin >> user2_id >> user2_level;

    User user = User();

    cout << "user " << user.id << " lv " << user.level << endl;

    user.id = user2_id;
    user.level = user2_level;

    cout << "user " << user.id << " lv " << user.level;

    return 0;
}