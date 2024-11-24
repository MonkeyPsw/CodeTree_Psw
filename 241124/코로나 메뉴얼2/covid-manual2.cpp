#include <iostream>
using namespace std;

int main() {
	char symp[3];
    int tem[3];
	int cnt_Arr[5] = {};

	for (int i = 0; i < 3; i++)
		cin >> symp[i] >> tem[i];

	for (int i = 0; i < 3; i++)
	{
		if (symp[i] == 'Y')
		{
			if (tem[i] >= 37)
				cnt_Arr[1]++;
			else
				cnt_Arr[3]++;
		}
		else
		{
			if (tem[i] >= 37)
				cnt_Arr[2]++;
			else
				cnt_Arr[4]++;
		}
	}

	for (int i = 1; i < 5; i++)
		cout << cnt_Arr[i] << " ";
	if (cnt_Arr[1] >= 2)
		cout << 'E';

	/*
	/ 카운팅 배열의 1에는 A인 사람의 수가, 2에는 B가, 3에는 C가, 4에는 D가 들어감
	int count_arr[5] = {};
	// type num = 분류 번호
	int type_num = 0;
	char s;
	int t;
	
	// s와 t를 입력받은 후 카운팅 배열을 통해 각각의 빈도 저장
	for(int i = 0; i < 3; i++) {
		cin >> s >> t;

		if(t >= 37 && s == 'Y')
			type_num = 1;
		else if(t >= 37)
			type_num = 2;
		else if(s == 'Y')
			type_num = 3;
		else
			type_num = 4;
		count_arr[type_num]++;
	}
	
    // A부터 D까지 나온 횟수를 출력
    for(int i = 1; i <= 4; i++) {
        cout << count_arr[i] << " ";
    }
	
	if(count_arr[1] >= 2)
		cout << "E";

	*/
	
	return 0;
}