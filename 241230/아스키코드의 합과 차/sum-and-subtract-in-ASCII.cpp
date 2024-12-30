#include <iostream>
using namespace std;

int main() {
    char a, b;

    cin >> a >> b;

    int a_num = (int)a;
    int b_num = (int)b;

    cout << a_num + b_num << " " << (a_num >= b_num ? a_num - b_num : b_num - a_num);

    return 0;
}