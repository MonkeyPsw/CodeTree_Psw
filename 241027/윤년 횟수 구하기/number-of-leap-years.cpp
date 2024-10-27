#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    
    cin >> n;
    cnt = n;

    for (int i = n; i >= 1; i--)
    {
        if (i % 4 != 0 || i % 100 == 0 && i % 400 != 0)
            cnt--;
    }

    /*
    윤년 조건
    4의 배수이면서 100의 배수가 아닌 수
    400의 배수
    for(int i = 1; i <= n; i++) {
		if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			cnt++;
	}
    */

    cout << cnt;
    return 0;
}