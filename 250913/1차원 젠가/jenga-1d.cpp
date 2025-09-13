#include <iostream>

using namespace std;

int n;
int blocks[100];
int s1, e1;
int s2, e2;
int tmp[100];
int cnt;

void TmpToBlock()
{
    for (int i = 0; i < cnt; i++)
        blocks[i] = tmp[i];
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

    n -= cnt;
    TmpToBlock();
    cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (i < s2 - 1 || i > e2 - 1)
            tmp[cnt++] = blocks[i];
    }

    cout << cnt << endl;
    
    for (int i = 0; i < cnt; i++)
        cout << tmp[i] << endl;

    return 0;
}
