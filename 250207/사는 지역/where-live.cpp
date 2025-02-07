#include <iostream>

#define MAX_N 10

using namespace std;

int n;
string name[MAX_N], street_address[MAX_N], region[MAX_N];

class People {
    public :
        string name, address, region;

        People(string name, string address, string region) {
            this->name = name;
            this->address = address;
            this->region = region;
        }

        People() {}
};

int main() {
    int idx = 0;
    People p[MAX_N];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cin >> street_address[i];
        cin >> region[i];

        p[i] = People(name[i], street_address[i], region[i]);

        if (name[idx] < name[i])
            idx = i;
    }

    cout << "name " << p[idx].name << endl;
    cout << "addr " << p[idx].address << endl;
    cout << "city " << p[idx].region;

    return 0;
}