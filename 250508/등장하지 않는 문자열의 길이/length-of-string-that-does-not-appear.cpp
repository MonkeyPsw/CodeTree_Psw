#include <iostream>
#include <string>

using namespace std;

int N;
string str;

int main() {
    cin >> N;
    cin >> str;

    for (int i = 1; i <= N; i++)
    {
        string sub = str.substr(0, i);

        for (int j = 1; j < N; j++)
        {
            if (i == N)
            {
                cout << N;
                return 0;
            }
            
            string sub2 = str.substr(j, i);

            if (sub2 == sub)
                break;

            if (sub2.length() != i)
            {
                cout << i;
                return 0;
            }
        }
    }

    return 0;
}