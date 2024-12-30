#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    int a_int, b_int;

    cin >> a >> b;

    for (int i = 0; i < a.length(); i++)
    {
        a_int = stoi(a);
        if (!isdigit(a[i]))
            a_int = stoi(a.substr(0, i));
    }

    for (int i = 0; i < b.length(); i++)
    {
        b_int = stoi(b);
        if (!isdigit(b[i]))
            b_int = stoi(b.substr(0, i));
    }

    cout << a_int + b_int;

    /* 해설에서는 인덱스를 찾아서 따로 변환
    // a의 정수로 변환 가능한 최대 인덱스를 찾습니다.
	for(int i = 0; i < len_a; i++)
		if(a[i] <= '9' && a[i] >= '0')
			idx1++;
		else break;
	
	// b의 정수로 변환 가능한 최대 인덱스를 찾습니다.
	for(int i = 0; i < len_b; i++)
		if(b[i] <= '9' && b[i] >= '0')
			idx2++;
		else break;
    */

    return 0;
}