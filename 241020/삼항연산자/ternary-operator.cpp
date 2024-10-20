#include <iostream>
#include <string>
using namespace std;

int main() {
    int score;
    string grade;

    cin >> score;

    grade = score == 100 ? "pass" : "failure";

    cout << grade;

    return 0;
}