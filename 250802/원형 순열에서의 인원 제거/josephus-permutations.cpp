#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> q;

int main() {
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        q.push(i);
    
    while (q.size())
    {
        for (int i = 1; i <= K - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }

        cout << q.front() << " ";

        q.pop();
    }

    return 0;
}
