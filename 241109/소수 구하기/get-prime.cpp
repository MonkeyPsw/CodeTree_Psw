#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int divCnt = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                divCnt++;
        }
        if (divCnt == 2)
            cout << i << " ";
    }
    /*
    // 1부터 n까지 소수를 구합니다.
	for(int i = 1; i <= n; i++) {
		if(i == 1) continue;
		bool isprime = true;
		
		for(int j = 2; j < i; j++)
			if(i % j == 0) isprime = false;
		
		if(isprime)
			cout << i << " ";
	}
    */
    return 0;
}