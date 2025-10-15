#include <iostream>
using namespace std;

int main() {
    int num;

    while (true)
    {
        cin >> num;

        if (num < 25)
            cout << "Higher";
        else if (num > 25)
            cout << "Lower";
        else
        {
            cout << "Good";
            break;
        }

        cout << endl;
    }

    return 0;
}