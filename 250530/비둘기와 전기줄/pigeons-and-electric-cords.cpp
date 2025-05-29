#include <iostream>
#include <string>

using namespace std;

int N;
int pigeon[100];
int position[100];
int ans;
string pigeonPos[11];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pigeon[i] >> position[i];
    }

    // 이거도 마음에 들진않네
    for (int i = 0; i < N; i++)
        pigeonPos[pigeon[i]] += to_string(position[i]);

    for (int i = 1; i <= 10; i++)
    {
        if (pigeonPos[i].length() >= 2)
        {
            for (int j = 1; j < pigeonPos[i].length(); j++)
            {
                if (pigeonPos[i][j] != pigeonPos[i][j - 1])
                    ans++;
            }
        }
    }

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

    cout << ans;

    return 0;
}