#include <iostream>
using namespace std;

int main() {
	int num, sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> num;
		sum += num;
	}
	cout << sum;
    /* 1차원 배열 파트라서 일단은
    // 크기가 10인 배열을 구현합니다.
    int arr[10];
    int sum = 0;

	// 0부터 9까지의 인덱스에 주어진 수를 차례대로 입력받습니다.
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
	
	// 입력받은 수들을  sum에 더합니다.
	for(int i = 0; i < 10; i++) {
        sum += arr[i];
    }
	
    // sum을 출력합니다.
    cout << sum;

    return 0;
    */
	return 0;
}