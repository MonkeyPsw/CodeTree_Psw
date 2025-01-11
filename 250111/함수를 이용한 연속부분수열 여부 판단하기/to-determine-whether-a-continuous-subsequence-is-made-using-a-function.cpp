#include <iostream>

using namespace std;

int n1, n2;
int a[100], b[100];

/* i < n1 - n2로 했다가 틀렸었는데 그냥 부등호 바꿔주면 됐구나
// n번째 인덱스부터 시작하는 n2길이의 a수열과
// b수열이 완전히 일치하는지 확인합니다..
bool IsSame(int n) {
    for(int i = 0; i < n2; i++)
        if(a[i + n] != b[i])
            return false;

    return true;
}

// b가 a의 연속부분수열인지 확인합니다.
bool IsSubsequence() {
    for(int i = 0; i <= n1 - n2; i++)
        if(IsSame(i))
            return true;
    
    return false;
}
*/

bool IsSame(int x, int y)
{
    if (x == y)
        return true;
    return false;
}

int main() {
    cin >> n1 >> n2;

    bool isSub = false;

    for (int i = 0; i < n1; i++) cin >> a[i];

    for (int i = 0; i < n2; i++) cin >> b[i];

    for (int i = 0; i < n1; i++)
    {
        if (isSub)
            break;

        if (IsSame(a[i], b[0]))
        {
            if (i + n2 - 1 <= n1)
            {
                for (int j = 0; j < n2; j++)
                {
                    if (!IsSame(a[i + j], b[j]))
                    {
                        isSub = false;
                        break;
                    }
                    else
                        isSub = true;
                }
            }
        }
    }

    cout << (isSub ? "Yes" : "No");

    return 0;
}