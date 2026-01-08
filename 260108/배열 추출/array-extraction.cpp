#include <iostream>
#include <queue>

using namespace std;

int n;
int x[200000];
priority_queue<int> pq;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (x[i])
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
