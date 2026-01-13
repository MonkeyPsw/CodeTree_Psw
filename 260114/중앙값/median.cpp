#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int t;
int m;
int arr[100000];

int main() {
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        priority_queue<int> pqLeft;
        priority_queue<int, vector<int>, greater<int> > pqRight;

        cin >> m;
        for (int j = 0; j < m; j++)
            cin >> arr[j];

        pqLeft.push(arr[0]);
        cout << pqLeft.top() << " ";

        for (int j = 1; j < m; j++)
        {
            if (pqLeft.top() <= arr[j])
                pqRight.push(arr[j]);
            else
                pqLeft.push(arr[j]);
            
            if (!(pqLeft.size() == pqRight.size() || pqLeft.size() == pqRight.size() + 1))
            {
                if (pqLeft.size() > pqRight.size())
                {
                    pqRight.push(pqLeft.top());
                    pqLeft.pop();
                }
                else
                {
                    pqLeft.push(pqRight.top());
                    pqRight.pop();
                }
            }

            if (j % 2 == 0)
                cout << pqLeft.top() << " ";
        }

        cout << endl;
    }

    return 0;
}