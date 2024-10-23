#include <iostream>
using namespace std;

int main() {
    int gen, age;
    cin >> gen >> age;
    if (gen)
    {
        if (age >= 19)
            cout << "WOMAN";
        else
            cout << "GIRL";
    }
    else
    {
        if (age >= 19)
            cout << "MAN";
        else
            cout << "BOY";
    }
    return 0;
}