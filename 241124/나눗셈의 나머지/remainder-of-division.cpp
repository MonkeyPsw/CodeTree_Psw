#include <iostream>
using namespace std;

int main() {
    int a, b, cnt = 0, sum = 0;
	int arr[100];
	int cnt_Arr[10] = {};

    cin >> a >> b;

	/* 나머지를 바로 저장할수도 있구나
	// a가 1 이하가 될 때 까지 나누면서 나머지를 count배열에 저장하기
	while(a > 1) {
        count_arr[a % b]++;
        a /= b;
    }
	
    // 나머지가 나온 횟수를 구해 정답 구하기
    for(int i = 0; i < b; i++) {
        ans += count_arr[i] * count_arr[i];
    }
	*/

    while (a > 1)
    {
        arr[cnt++] = a % b;
		a /= b;
    }
	
	for (int i = 0; i < cnt; i++)
		cnt_Arr[arr[i]]++;

	for (int i = 0; i < 10; i++)
		sum += cnt_Arr[i] * cnt_Arr[i];

	cout << sum;

    return 0;
}