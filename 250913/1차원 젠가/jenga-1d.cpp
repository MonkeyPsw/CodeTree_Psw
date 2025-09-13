#include <iostream>

using namespace std;

int n;
int blocks[100];
int s1, e1;
int s2, e2;
int tmp[100];
int cnt, cnt2;

void TmpToBlock()
{
    for (int i = 0; i < cnt; i++)
        blocks[i] = tmp[i];
    
    for (int i = 0; i < 100; i++)
        tmp[i] = 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    for (int i = 0; i < n; i++)
    {
        if (i < s1 - 1 || i > e1 - 1)
            tmp[cnt++] = blocks[i];
    }

    TmpToBlock();

    for (int i = 0; i < cnt; i++)
    {
        if (i < s2 - 1 || i > e2 - 1)
            tmp[cnt2++] = blocks[i];
    }
    
    cout << cnt2 << endl;
    
    for (int i = 0; i < cnt2; i++)
        cout << tmp[i] << endl;

    return 0;
}
