#include <iostream>
#include <algorithm>

using namespace std;

int n;
string name[10];
int score1[10];
int score2[10];
int score3[10];

class Student {
    public :
        string name;
        int kor, eng, math;

        Student(string name, int score1, int score2, int score3) {
            this->name = name;
            kor = score1;
            eng = score2;
            math = score3;
        }

        Student() {}
};

bool cmp(Student a, Student b)
{
    return a.kor + a.eng + a.math < b.kor + b.eng + b.math;
}

int main() {
    Student s[10];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cin >> score1[i];
        cin >> score2[i];
        cin >> score3[i];

        s[i] = Student(name[i], score1[i], score2[i], score3[i]);
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