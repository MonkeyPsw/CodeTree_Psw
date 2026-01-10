#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

struct cmp {
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        
        return abs(a) > abs(b);
    }
};

const int MAX_N = 100000;
int n;
int x[MAX_N];
priority_queue<int, vector<int>, cmp> pq;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (x[i] != 0)
            pq.push(x[i]);
        else
        {
            if (pq.empty())
                cout << 0 << endl;
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }

    return 0;
}
