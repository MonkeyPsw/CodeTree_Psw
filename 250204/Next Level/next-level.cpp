#include <iostream>
#include <string>

using namespace std;

string user2_id;
int user2_level;

class User {
    public :
        string id;
        int level;

        User(string id = "", int level = 0) {
            this->id = id;
            this->level = level;
        }
};

int main() {
    cin >> user2_id >> user2_level;

    User user1 = User();

    user1.id = "codetree";
    user1.level = 10;

    cout << "user " << user1.id << " lv " << user1.level << endl;

    User user2 = User();

    user2.id = user2_id;
    user2.level = user2_level;

    cout << "user " << user2.id << " lv " << user2.level;

    return 0;
}