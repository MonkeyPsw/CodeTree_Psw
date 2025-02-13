#include <iostream>
#include <algorithm>

using namespace std;

int n;
string name[10];
int height[10];
int weight[10];

class Data {
    public :
        string name;
        int height, weight;

        Data(string n, int h, int w) {
            name = n;
            height = h;
            weight = w;
        }

        Data() {}
};

bool cmp(Data a, Data b)
{
    if (a.height != b.height)
        return a.height < b.height;
    return a.weight > b.weight;
}

int main() {
    Data d[10];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> height[i] >> weight[i];

        d[i] = Data(name[i], height[i], weight[i]);
    }

    sort(d, d + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << d[i].name << " ";
        cout << d[i].height << " ";
        cout << d[i].weight << endl;
    }

    return 0;
}