#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string name[10];
int korean[10];
int english[10];
int math[10];

class Score {
    public :
        string name;
        int kor, eng, math;

        Score(string name, int score1, int score2, int score3) {
            this->name = name;
            kor = score1;
            eng = score2;
            math = score3;
        }

        Score() {}
};

bool cmp(Score a, Score b)
{
    if (a.kor == b.kor)
    {
        if (a.eng == b.eng)
            return a.math > b.math;
        
        return a.eng > b.eng;
    }

    return a.kor > b.kor;
}

int main() {
    Score s[10];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cin >> korean[i];
        cin >> english[i];
        cin >> math[i];

        s[i] = Score(name[i], korean[i], english[i], math[i]);
    }

    sort(s, s + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << s[i].name << " ";
        cout << s[i].kor << " ";
        cout << s[i].eng << " ";
        cout << s[i].math << endl;
    }

    return 0;
}