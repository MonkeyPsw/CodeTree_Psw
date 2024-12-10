#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;

    int a, b, c;
    a = str1.length();
    b = str2.length();
    c = str3.length();

    if (a >= b)
    {
        if (a >= c)
        {
            if (b >= c)
                cout << a - c;
            else
                cout << a - b;
        }
        else
            cout << c - b;
    }
    else
    {
        if (b >= c)
        {
            if (a >= c)
                cout << b - c;
            else
                cout << b - a;
        }
        else
            cout << c - a;
    }

    /* 해설 방식은 그냥 단순하게 했네
    // 세 문자열 중 가장 긴 길이와 가장 짧은 길이를 구합니다.
    int mx = len1;
    if(mx < len2) mx = len2;
    if(mx < len3) mx = len3;
    int mn = len1;
    if(mn > len2) mn = len2;
    if(mn > len3) mn = len3;
    */

    return 0;
}