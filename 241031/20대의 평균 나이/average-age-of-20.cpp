#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0, sum = 0;

    while (true)
    {
        cin >> n;
        if (n >= 20 && n < 30)
        {
            sum += n;
            cnt++;
        }
        else
        {
            cout << fixed;
            cout.precision(2);
            cout << (double)sum / cnt;
            break;
        }
    }
    /* else를 안쓰는게 좋나?
    while(1) {
        // 변수를 선언하고 입력을 받습니다.
        int n;
        cin >> n;
        
        // 입력받은 값이 20대가 아니면 종료합니다.
        if(n >= 30 || n <= 19) {
            cout << fixed;
            cout.precision(2);
            cout << (double)sum / cnt;
            break;
        }

        // 20대가 맞는 경우에는, 계속 값을 계산해줍니다.
        sum += n;
        cnt++;
    }
    */
    return 0;
}