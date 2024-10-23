#include <iostream>
using namespace std;

int main() {
    char aSymp, bSymp, cSymp;
    int aTem, bTem, cTem, emerCnt = 0;

    cin >> aSymp >> aTem;
    cin >> bSymp >> bTem;
    cin >> cSymp >> cTem;

    if (aSymp == 'Y' && aTem >= 37)
        emerCnt++;
    if (bSymp == 'Y' && bTem >= 37)
        emerCnt++;
    if (cSymp == 'Y' && cTem >= 37)
        emerCnt++;

    if (emerCnt >= 2)
        cout << 'E';
    else
        cout << 'N';

    /* 중첩 조건문
    // A가 2명 이상인지 판단하기
    if(c1 == 'Y' && t1 >= 37) {
        // 첫 번째 사람이 A라면, 남은 두 사람 중 한 사람이라도 A면 됩니다.
        if((c2 == 'Y' && t2 >= 37) || (c3 == 'Y' && t3 >= 37))
            cout << "E";
        else
            cout << "N";
    }
    else {
        // 첫 번째 사람이 A가 아니라면, 남은 두 사람 모두 A여야만 합니다.
        if((c2 == 'Y' && t2 >= 37) && (c3 == 'Y' && t3 >= 37))
            cout << "E";
        else
            cout << "N";
    }
    */
    return 0;
}