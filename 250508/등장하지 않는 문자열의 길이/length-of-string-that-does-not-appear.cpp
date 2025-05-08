#include <iostream>
#include <string>

using namespace std;

int N;
string str;
string sub;

int main() {
    cin >> N;
    cin >> str;

    // i 부분문자열길이, j k 시작점
    for (int i = 1; i <= N; i++)
    {
        bool isAppear = false;

        for (int j = 0; j <= N - i; j++)
        {
            sub = str.substr(j, i);

            for (int k = j + 1; k <= N - i; k++)
            {
                string sub2 = str.substr(k, i);

                if (sub2 == sub)
                {
                    isAppear = true;
                    break;
                }
            }
        }

        if (!isAppear)
        {
            cout << i;
            return 0;
        }
    }
    
    cout << N;

    return 0;
}