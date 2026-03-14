#include <iostream>
#include <algorithm>
#include <tuple>
#include <functional>

using namespace std;

int N, M;
int w[100000];
int v[100000];
tuple<double, int, int> arr[100000];
double ans;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i < N; i++)
        arr[i] = make_tuple((double)v[i] / w[i], w[i], v[i]);
    
    sort(arr, arr + N, greater<>());

    for (int i = 0; i < N; i++)
    {
        double ratio = 0;
        int weight = 0, value = 0;
        tie(ratio, weight, value) = arr[i];

        if (M >= weight)
        {
            ans += value;
            M -= weight;
        }
        else
        {
            ans += (double)ratio * M;
            break;
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << ans;
    
    return 0;
}
