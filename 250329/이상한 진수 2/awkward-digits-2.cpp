#include <iostream>

using namespace std;

string a;
int num;
bool isAllOne = true;

int main() {
    cin >> a;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '0')
        {
            a[i] = '1';
            isAllOne = false;
            break;
        }
    }

    if (isAllOne)
        a[a.length() - 1] = '0';

    for (int i = 0; i < a.length(); i++)
        num = num * 2 + (a[i] - '0');

    /* 사실 완전탐색은 이게 맞긴한데 굳이?
    // 각 i번째 자릿수를 바꾸었을 때의 십진수 값을 구해줍니다.
	int ans = INT_MIN;
    for(int i = 0; i < (int) binary.size(); i++) {
		// i번째 자릿수를 바꿉니다.
		binary[i] = '0' + '1' - binary[i];
		// 십진수로 변환합니다.
    	int num = 0;
    	for(int j = 0; j < (int) binary.size(); j++)
        	num = num * 2 + (binary[j] - '0');
		
		// 가능한 십진수 값 중 최댓값을 구해줍니다.
		ans = max(ans, num);
		
		// i번째 자릿수를 원래대로 돌려놓습니다.
		binary[i] = '0' + '1' - binary[i];
	}
    */

    cout << num;

    return 0;
}