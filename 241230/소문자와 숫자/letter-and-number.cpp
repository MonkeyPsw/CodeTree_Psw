#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str;
    
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]) || isdigit(str[i]))
            cout << (char)tolower(str[i]);
        /* 조건 따로 주는게 맞긴 하겠네
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			cout << (char)tolower(str[i]);
		}
		
		if(str[i] >= '0' && str[i] <= '9') {
			cout << str[i];
		}
        */
    }

    return 0;
}