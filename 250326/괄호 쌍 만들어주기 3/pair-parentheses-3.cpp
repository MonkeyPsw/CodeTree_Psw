#include <iostream>
#include <string>

using namespace std;

string A;
int cnt;

int main() {
    cin >> A;

    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '(')
        {
            for (int j = i + 1; j < A.length(); j++)
            {
                if (A[j] == ')')
                    cnt++;
            }
        }
    }

    /* 완전탐색은 이게 더 어울리나 어차피 둘다 O(N²)라서 흠
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(str[i] == '(' && str[j] == ')')
                cnt++;
    */

    cout << cnt;

    return 0;
}