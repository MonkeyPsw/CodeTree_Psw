#include <iostream>
using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    cout << a / b << ".";
    if (a >= b)
        a = a - b;
    for (int i = 0; i < 20; i++)
    {
        cout << a * 10 / b;
        a = a * 10 - b * (a * 10 / b);
    }

    /*
    // a를 b로 나눈 나머지를 시작으로
    // 소수점 자리를 하나씩 계산합니다.
    a %= b;
	for(int i = 0; i < 20; i++) {
        // 나머지에 10 곱한 값을 기준으로
        // b로 나누었을 떄의 몫을 구해줍니다.
		a *= 10;
        cout << a / b;
        
        // a를 b로 나눈 나머지를 게속 갱신해줍니다.
		a %= b;
	}
    */

    return 0;
}