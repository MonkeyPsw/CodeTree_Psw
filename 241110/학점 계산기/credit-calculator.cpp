#include <iostream>
using namespace std;

int main() {
    int n;
    double avg, sum = 0;
    double score[5];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
        sum += score[i];
    }
    avg = sum / n;
    cout << fixed;
    cout.precision(1);
    cout << avg << endl;
    if (avg >= 4.0)
        cout << "Perfect";
    else if (avg >= 3.0)
        cout << "Good";
    else
        cout << "Poor";
    return 0;
}