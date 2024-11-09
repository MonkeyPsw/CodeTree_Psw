#include <iostream>
using namespace std;

int main() {
    int n, cnt = 65;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << (char)cnt++;
        cout << endl;
    }
    /*
    char cnt = 'A';
	
	// 알파벳을 정사각형 모양으로 출력합니다.
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << cnt;
			cnt++;
		}
		cout << endl;
	}
    */
    return 0;
}