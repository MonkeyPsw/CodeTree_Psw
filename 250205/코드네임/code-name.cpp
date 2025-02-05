#include <iostream>

#define MAX_N 5

using namespace std;

char codename[MAX_N];
int score[MAX_N];

class Spy {
    public :
        char codename;
        int score;

        Spy(char codename, int score) {
            this->codename = codename;
            this->score = score;
        }

        Spy() {}
};

int main() {
    for (int i = 0; i < MAX_N; i++) {
        cin >> codename[i] >> score[i];
    }

    int minIdx = 0;
    Spy SpyInfo[MAX_N];

    for (int i = 0; i < MAX_N; i++)
    {
        SpyInfo[i] = Spy(codename[i], score[i]);
        
        if (score[minIdx] > score[i])
            minIdx = i;
    }

    cout << SpyInfo[minIdx].codename << " " << SpyInfo[minIdx].score;

    return 0;
}
