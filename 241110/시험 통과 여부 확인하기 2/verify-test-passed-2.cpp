#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    int Score[4];
    int Sum[10] = {}; // sum은 굳이 배열 안해도 되는거였다.
    // 교실에는 10명보다 적은 학생들이 있습니다.
    // 첫 번째 줄에 10명 미만의 학생수가 주어집니다.
    // 라면서 두번째 테스트 케이스가 10인데 뭐냐 이거.

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> Score[j];
            Sum[i] += Score[j];
        }
        if ((double)Sum[i] / 4 >= 60)
        {
            cout << "pass";
            cnt++;
        }
        else
            cout << "fail";
        cout << endl;
    }
    cout << cnt;
    
    return 0;
}