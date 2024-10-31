#include <iostream>
using namespace std;

int main() {
    int n, x = 0;
    cin >> n;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            x++;
        }
    }
    /* 솔루션
    int prod = 1;
    while(1) {
		// prod가 n이 될 때까지 2를 곱합니다.
		if(n == prod)
			break;
		
		prod *= 2;
		x++;
    }
    */
    cout << x;
    return 0;
}