#include <iostream>
#include <algorithm>

using namespace std;

int n;
string name[10];
int height[10];
int weight[10];

class People {
    public :
        string name;
        int height, weight;

        People(string name, int height, int weight) {
            this->name = name;
            this->height = height;
            this->weight = weight;
        }

        People() {}
};

bool CmpHeight(People a, People b)
{
    return a.height < b.height;
}

int main() {
    People p[10];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cin >> height[i];
        cin >> weight[i];

        p[i] = People(name[i], height[i], weight[i]);
    }

    sort(p, p + n, CmpHeight);

    for (int i = 0; i < n; i++)
        cout << p[i].name << " " << p[i].height << " " << p[i].weight << endl;

    return 0;
}