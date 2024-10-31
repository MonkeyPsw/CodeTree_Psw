#include <iostream>
using namespace std;

int main() {
    int width, length;
    char c;
    
    while (true)
    {
        cin >> width >> length >> c;
        cout << width * length << endl;
        if (c == 'C')
            break;
    }
    
    return 0;
}