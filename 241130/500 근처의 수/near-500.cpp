#include <iostream>
using namespace std;

int main() {
    int num;
    int up[10], down[10];
    int upCnt = 0, downCnt = 0;

    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        if (num > 500)
            up[upCnt++] = num;
        else
            down[downCnt++] = num;
    }

    int downMax = down[0];
    int upMin = up[0];
    
    for (int i = 1; i < downCnt; i++)
    {
        if (down[i] > downMax)
            downMax = down[i];
    }
    for (int i = 1; i < upCnt; i++)
    {
        if (up[i] < upMin)
            upMin = up[i];
    }

    cout << downMax << " " << upMin;
    
    /* 나 왜 이렇게 어렵게 했지.
    // max_val : 500 미만의 가장 큰 수, min_val : 500 초과의 가장 작은 수
	int max_val = 1;
	int min_val = 1000;
	
	// 10개의 숫자들 중 500근처의 수들을 구합니다.
	for(int i = 0; i < 10; i++) {
		if(arr[i] < 500 && arr[i] > max_val)
			max_val = arr[i];
		
		if(arr[i] > 500 && arr[i] < min_val)
			min_val = arr[i];
	}
	
    // 구한 값을 출력합니다.
    cout << max_val << " " << min_val;
    */

    return 0;
}