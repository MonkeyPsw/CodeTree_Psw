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

/* 해설은 substr 대신 인덱스를 직접 비교해서 좀 빠르겠군
int main() {
    cin >> N;
    cin >> str;

    int ans = 1;

    for (int i = 1; i < N; i++)
    {
        bool isAppear = false;

        for (int j = 0; j <= N - i; j++)
        {
            for (int k = j + 1; k <= N - i; k++)
            {
                bool isSame = true;

                for (int l = 0; l < i; l++)
                {
                    if (str[j + l] != str[k + l])
                    {
                        isSame = false;
                        break;
                    }
                }

                if (isSame)
                    isAppear = true;
            }
        }

        if (isAppear)
            ans = i + 1;
        else
            break;
    }
    
    cout << ans;

    return 0;
}
*/