#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    bool isDel = true;

    cin >> a >> b;

    /* while문 조건을 이렇게 하면 되는거였군
    // A에서 B를 찾습니다, 찾을 수 없을 때까지 반복합니다.
    while(A.find(B) != string::npos){
        int start_pos = A.find(B);
        // start_pos부터 B.length()개의 문자를 지웁니다.
        A.erase(start_pos, B.length());
    }
    */
    while (isDel)
    {
        int idx = -1;

        if (a.find(b) != string::npos)
        {
            idx = a.find(b);
            a.erase(idx, b.length());
        }
        else
            isDel = false;
    }

    cout << a;

    return 0;

    /*
    while(true) {
        // a문자열에서 b문자열이 처음 등장하는 위치를 찾습니다.
        int idx = -1;
        
        // Tip1: 우리는 i, i+1, ..., i+len_b-1을 비교할 것입니다.
        // 이 때 마지막 위치는 i+len_b-1 < len_a를 만족해야
        // 하므로 i < len_a - len_b + 1을 구할 수 있습니다.

        int candidates = len_a - len_b + 1;
        for(int i = 0; i < candidates; i++) {
            // i부터 b길이만큼 비교해서 b와 같은지 체크합니다.
            bool is_same = true;
            for(int j = 0; j < len_b; j++) {
                if(str_a[i + j] != str_b[j]) {
                    is_same = false;
                    break;
                }
            }
            if(is_same) {
                // 문자열을 찾았으므로 i 반환
                idx = i;
                break;
            }
        }

        // 찾지 못한 경우
        if(idx == -1)
            break;
        
        // a문자열에서 idx위치에서 b문자열의 길이만큼의 문자를 지웁니다.
        str_a = str_a.substr(0, idx) + str_a.substr(idx + len_b);

        len_a = str_a.length();
    }
    */
}