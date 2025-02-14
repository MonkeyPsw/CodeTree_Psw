#include <iostream>
#include <algorithm>

using namespace std;

int N;
int x[1000];
int y[1000];

class Point {
    public :
        int x, y, index;

        Point(int x, int y, int n) {
            if (x < 0)
                x *= -1;
            if (y < 0)
                y *= -1;

            this->x = x;
            this->y = y;
            index = n;
        }

        Point() {}
};

bool cmpDistance(Point a, Point b)
{
    int aDist, bDist;

    aDist = a.x + a.y;
    bDist = b.x + b.y;

    if (aDist == bDist)
        return a.index < b.index;
    return aDist < bDist;
}

int main() {
    Point p[1000];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];

        p[i] = Point(x[i], y[i], i + 1);
    }

    sort(p, p + N, cmpDistance);

    for (int i = 0; i < N; i++)
        cout << p[i].index << endl;

    return 0;
}
