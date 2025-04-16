#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int x[100];
int y[100];
int ans = 0;
// double인가 했는데 괜한 실수였고 아오 바보

/* 삼각형의 넓이 사선 공식 (신발끈 공식)
// 삼각형의 넓이에 2를 곱한 값을 반환합니다.
int area(int i, int j, int k) {
    return abs((x[i] * y[j] + x[j] * y[k] + x[k] * y[i]) - 
               (x[j] * y[i] + x[k] * y[j] + x[i] * y[k]));
}
*/

int CalTriX(int a, int b, int c)
{
    if (x[a] == x[b])
        return abs(x[c] - x[a]);
    else if (x[a] == x[c])
        return abs(x[b] - x[a]);
    else if (x[b] == x[c])
        return abs(x[a] - x[b]);
}

int CalTriY(int a, int b, int c)
{
    if (y[a] == y[b])
        return abs(y[c] - y[a]);
    else if (y[a] == y[c])
        return abs(y[b] - y[a]);
    else if (y[b] == y[c])
        return abs(y[a] - y[b]);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    // y가 같으면 x축 평행, x가 같으면 y축 평행
    // 2개만 같아야 한다? 
    
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (x[i] != x[j] && x[i] != x[k] && x[j] != x[k] ||
                    y[i] != y[j] && y[i] != y[k] && y[j] != y[k])
                    continue;
                
                int valX = CalTriX(i, j, k);
                int valY = CalTriY(i, j, k);
                int tmp = valX * valY;

                ans = max(ans, tmp);
            }
        }
    }

    // 왜 출력이 곱하기2인가 했네 아 틀릴게 아닌데
    cout << ans;

    return 0;
}