#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
string command;
priority_queue<int> pq;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> command;

        if (command == "push")
        {
            int x;
            cin >> x;

            pq.push(x);
        }
        else if (command == "pop")
        {
            cout << pq.top() << endl;
            pq.pop();
        }
        else if (command == "size")
            cout << pq.size() << endl;
        else if (command == "empty")
            cout << pq.empty() << endl;
        else
            cout << pq.top() << endl;
    }

    return 0;
}
