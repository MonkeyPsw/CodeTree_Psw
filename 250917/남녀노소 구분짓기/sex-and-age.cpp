#include <iostream>
using namespace std;

int main() {
    int sex, age;

    cin >> sex >> age;

    if (sex)
    {
        if (age < 19)
            cout << "GIRL";
        else
            cout << "WOMAN";
    }
    else
    {
        if (age < 19)
            cout << "BOY";
        else
            cout << "MAN";
    }
    
    return 0;
}