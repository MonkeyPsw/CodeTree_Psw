#include <iostream>
#include <string>

using namespace std;

string text;
string pattern;

/*
bool IsSubStr(int start_idx) {
    int n = (int) text.size();
    int m = (int) pattern.size();

    // 만약 pattern을 매칭 시키기에
    // text 문자열 범위를 초과하게 된다면
    // 부분 문자열이 될 수 없으므로 false를 반환합니다.
    if(start_idx + m - 1 >= n)
        return false;

    for(int j = 0; j < m; j++) {
        // 하나라도 다르다면, 부분 문자열이 아니므로 false를 반환합니다.
        if(text[start_idx + j] != pattern[j])
            return false;
    }

    // 전부 일치한다면 부분 문자열이므로 true를 반환합니다.
    return true;
}

// 부분 문자열의 위치를 찾아 반환합니다.
int FindIndex() {
    int n = (int) text.size();
    for(int i = 0; i < n; i++) {
        // i번째를 시작으로 부분 문자열이 된다면, 해당 위치를 반환합니다.
        if(IsSubStr(i))
            return i;
    }

    // 없다면, -1을 반환합니다.
    return -1;
}
*/

int FindString()
{
    if (text.find(pattern) != string::npos)
        return text.find(pattern);
    return -1;
}

int main() {
    cin >> text;
    cin >> pattern;

    cout << FindString();

    return 0;
}