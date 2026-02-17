#include <iostream>
#include <algorithm>

using namespace std;

string word;
int alpha[26];
int j, ans;

int main() {
    cin >> word;

    for (int i = 0; i < word.length(); i++)
    {
        while (j < word.length() && alpha[word[j] - 'a'] == 0)
        {
            alpha[word[j] - 'a']++;
            j++;
        }

        ans = max(ans, j - i);

        alpha[word[i] - 'a']--;
    }

    cout << ans;

    return 0;
}
