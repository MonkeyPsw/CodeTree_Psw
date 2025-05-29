#include <iostream>
#include <string>

using namespace std;

int N;
int pigeon[100];
int position[100];
int ans;
string strPigeonPos[11];
int pigeonPos[11];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pigeon[i] >> position[i];
    }

    /*
    // 이거도 마음에 들진않네
    for (int i = 0; i < N; i++)
        strPigeonPos[pigeon[i]] += to_string(position[i]);

    for (int i = 1; i <= 10; i++)
    {
        if (strPigeonPos[i].length() >= 2)
        {
            for (int j = 1; j < strPigeonPos[i].length(); j++)
            {
                if (strPigeonPos[i][j] != strPigeonPos[i][j - 1])
                    ans++;
            }
        }
    }
    */

    // 해설을 보니 이 아이디어가 맞긴했네
    // 초기위치 처음 보인 값으로 지정하고 위치가 달라지면 증가 후 갱신
    // 여기서 처음에 -1로 전체 초기화 하고 하려다가 위 코드로 했는데 으앙
    /* 뭔가 해보다가 그냥 다시하기로 함
    for (int i = 0; i < N; i++)
    {
        if (pigeonPos[pigeon[i]] == 0)
        {
            if (position[i] == 0)
                pigeonPos[pigeon[i]] = -1;
            else
                pigeonPos[pigeon[i]] = position[i];
        }
        else
        {
            if (pigeonPos[pigeon[i]] != position[i])
            {
                ans++;
                if (position[i] == 1)
                    pigeonPos[pigeon[i]] = position[i];
                else
                    pigeonPos[pigeon[i]] = -1;
            }
        }
    }
    */

    // 그래 이게 맞지
    for (int i = 1; i <= 10; i++)
        pigeonPos[i] = -1;

    for (int i = 0; i < N; i++)
    {
        if (pigeonPos[pigeon[i]] < 0)
            pigeonPos[pigeon[i]] = position[i];
        else
        {
            if (pigeonPos[pigeon[i]] != position[i])
            {
                ans++;
                pigeonPos[pigeon[i]] = position[i];
            }
        }
    }

    cout << ans;

    return 0;
}