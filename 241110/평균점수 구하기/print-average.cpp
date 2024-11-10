#include <iostream>
using namespace std;

int main() {
    double avg, sum = 0;
    double score[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> score[i];
        sum += score[i];
    }
    avg = sum / 8;
    cout << fixed;
    cout.precision(1);
    cout << avg;
    return 0;
}