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
        
    return 0;
}