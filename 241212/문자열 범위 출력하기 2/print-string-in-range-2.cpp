#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr;
    int n;

	cin >> arr >> n;

    if (arr.length() <= n)
    {
        for (int i = arr.length() - 1; i >= 0; i--)
            cout << arr[i];
    }
    else
    {
        for (int i = arr.length() - 1; i >= arr.length() - n; i--)
            cout << arr[i];
    }
    
    /*
    // 문자열의 맨 뒤에서부터 주어진 개수만큼 출력합니다.
	for(int i = len - 1; i >= 0; i--) {
		// 주어진 개수만큼 출력했을 경우 for문을 나갑니다.
		if(cnt >= a)
			break;
		cout << str[i];
		cnt++;
	}
    */

    return 0;
}