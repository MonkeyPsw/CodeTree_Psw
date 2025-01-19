#include <iostream>

using namespace std;

int N;
int cnt;

/*
// n에서 시작하여 1이 되기 위해
// 거쳐야하는 횟수를 반환하는 함수입니다.
int GetNum(int n) {
    // 1이면 더 이상 진행할 작업이 없으므로 0회가 더 필요합니다.
    if(n == 1)
        return 0;

    // 짝수라면 2로 나눠 진행했을 때의 횟수 + 1번이 소요됩니다.
    if(n % 2 == 0)
        return GetNum(n / 2) + 1;
    // 홀수라면 3으로 나누었을 때의 몫을 가지고 진행했을 때의 횟수 + 1번
    // 소요됩니다.
    else
        return GetNum(n / 3) + 1;
}
*/

int MakeNumber(int n)
{
    if (n == 1)
        return cnt;

    cnt++;

    if (n % 2 == 0)
        return MakeNumber(n / 2);
    else
        return MakeNumber(n / 3);
}

int main() {
    cin >> N;

    cout << MakeNumber(N);

    return 0;
}