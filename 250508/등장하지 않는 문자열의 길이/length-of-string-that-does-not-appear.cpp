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

                /* 이런 느낌으로 인덱스 직접 비교가 빠르긴 할듯
                for (int l = 0; l < i; l++)
                {
                    bool isSame = true;

                    if (str[j + l] != str[k + l])
                    {
                        isSame = false;
                        break;
                    }
                    
                    if (isSame)
                        isAppear = true;
                }
                */
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