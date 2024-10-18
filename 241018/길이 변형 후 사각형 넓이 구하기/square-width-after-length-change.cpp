#include <iostream>
using namespace std;

int main() {
    int width, length;
    cin >> width >> length;
    width += 8;
    cout << width << endl;
    length *= 3;
    cout << length << endl;
    cout << width * length;
    return 0;
}