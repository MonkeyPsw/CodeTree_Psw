#include <iostream>
using namespace std;

int main() {
    int y;
    cin >> y;
    // y % 4 == 0 && y % 100 != 0) || y % 400 == 0 true 이게 더 낫네
    if (y % 4 != 0 || y % 100 == 0 && y % 400 != 0)
        cout << "false";
    else
        cout << "true";
    /*
    굳이 이렇게?
    if(y % 4 == 0) {
		if(y % 100 == 0) {
			if(y % 400 == 0) {
				cout << "true";
			}
			else {
				cout << "false";
			}
		}
		else {
			cout << "true";
		}
	}
	else {
		cout << "false";
	}
    */

    return 0;
}