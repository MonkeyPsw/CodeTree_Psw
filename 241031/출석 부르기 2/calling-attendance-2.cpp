#include <iostream>
using namespace std;

int main() {
    int n;
    while (true)
    {
        cin >> n;
        if (n == 1)
            cout << "John";
        else if (n == 2)
            cout << "Tom";
        else if (n == 3)
            cout << "Paul";
        else if (n == 4)
            cout << "Sam";
        else
        {
            cout << "Vacancy";
            break;
        }
        cout << endl;
    }
    return 0;
}