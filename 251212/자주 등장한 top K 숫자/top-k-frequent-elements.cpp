#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n, k;
int arr[100000];
unordered_map<int, int> iMap;
vector<pair<int, int>> v; // (숫자, 빈도) 페어를 담을 동적배열

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second != b.second)
        return a.second > b.second;

    return a.first > b.first;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        iMap[arr[i]]++;
    }

    unordered_map<int, int>::iterator it;
    for (it = iMap.begin(); it != iMap.end(); it++)
        v.push_back(make_pair(it->first, it->second));

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < k; i++)
        cout << v[i].first << " ";

    return 0;
}
