#include <iostream>
#include <string>

using namespace std;

string A;

/* 속도가 매우 중요하다면 이런식으로 가운데를 기준으로 대칭문자 확인
bool Palindrome(string &s) {
    for(int i = 0; i < (int) s.size(); i++)
        if(s[i] != s[(int) s.size() - i - 1])
            return false;
    
    return true;
}
*/

void IsPalindrome(string &s)
{
    string rev_s;

    for (int i = s.length() - 1; i >= 0; i--)
        rev_s += s[i];

    if (s == rev_s)
        cout << "Yes";
    else
        cout << "No";
}

int main() {
    cin >> A;

    IsPalindrome(A);

    return 0;
}