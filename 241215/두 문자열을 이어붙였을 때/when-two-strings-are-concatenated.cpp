#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << (str1 + str2 == str2 + str1 ? "true" : "false");
    /* 문자열 비교는 아직이었군
    // 문자열 c에 문자열 a와 b를 붙입니다.
    string c = a + b;
	
	// 문자열 d에 문자열 b와 a를 붙입니다.
    string d = b + a;
	
	// 두 문자열이 같다면 true를, 같지 않다면 false를 출력합니다.
	if(c == d)
        cout << "true";
    else
        cout << "false";
    */
    return 0;
}