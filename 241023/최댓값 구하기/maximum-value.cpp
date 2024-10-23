#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a >= b && a >= c)
        cout << a;
    else if (b >= a && b >= c)
        cout << b;
    else
        cout << c;
    
    /* 중첩 조건문
    // a와 b를 비교한뒤, a가 b보다 크다면 a와 c를 비교하여 최댓값을 구합니다.
    if(a >= b) {
		if(a >= c)
			cout << a;
		else
			cout << c; 
	}		

	// a와 b를 비교한 결과가 나와있으므로, b와 c만 비교하여 최댓값을 구합니다.
	else {
		if(b >= c)
			cout << b;
		else
			cout << c;
	}
    */

    return 0;
}