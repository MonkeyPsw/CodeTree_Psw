#include <iostream>
#include <algorithm>

using namespace std;

string name[5];
int height[5];
double weight[5];

class Data {
    public :
        string name;
        int height;
        double weight;

        Data(string n, int h, double w) {
            name = n;
            height = h;
            weight = w;
        }

        Data() {}
};

bool cmpName(Data a, Data b)
{
    return a.name < b.name;
}

bool cmpHeight(Data a, Data b)
{
    return a.height > b.height;
}

int main() {
    Data d[5];

    for (int i = 0; i < 5; i++) {
        cin >> name[i] >> height[i] >> weight[i];

        d[i] = Data(name[i], height[i], weight[i]);
    }

    sort(d, d + 5, cmpName);

    cout << "name" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << d[i].name << " ";
        cout << d[i].height << " ";
        cout << d[i].weight << endl;
    }

    sort(d, d + 5, cmpHeight);

    cout << endl << "height" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << d[i].name << " ";
        cout << d[i].height << " ";
        cout << d[i].weight << endl;
    }

    return 0;
}