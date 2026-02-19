#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string word;
int k;
int alpha[26];
int cnt, j, ans;

int main() {
    cin >> word >> k;

    for (int i = 0; i < word.length(); i++)
    {
        while (j < word.length())
        {
            if (alpha[word[j] - 'a'] == 0 && cnt == k)
                break;
                        
            alpha[word[j] - 'a']++;
            if (alpha[word[j] - 'a'] == 1)
                cnt++;

            j++;
        }

        alpha[word[i] - 'a']--;
        if (alpha[word[i] - 'a'] == 0)
            cnt--;

        ans = max(ans, j - i);
    }

    cout << ans;

    return 0;
}
