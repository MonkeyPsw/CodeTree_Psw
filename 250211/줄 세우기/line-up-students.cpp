#include <iostream>
#include <algorithm>

using namespace std;

int N;
int h[1000];
int w[1000];

class Student {
    public :
        int height, weight, number;

        Student(int h, int w, int n) {
            height = h;
            weight = w;
            number = n;
        }

        Student() {}
};

bool cmp(Student a, Student b)
{
    if (a.height == b.height)
    {
        if (a.weight == b.weight)
            return a.number < b.number;
        return a.weight > b.weight;
    }

    return a.height > b.height;
}

int main() {
    Student s[1000];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> h[i] >> w[i];

        s[i] = Student(h[i], w[i], i + 1);
    }

    sort(s, s + N, cmp);

    for (int i = 0; i < N; i++)
    {
        cout << s[i].height << " ";
        cout << s[i].weight << " ";
        cout << s[i].number << endl;
    }

    return 0;
}
