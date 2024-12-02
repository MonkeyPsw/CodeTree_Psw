#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[1000];
    bool dup[1000];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dup[i] = false;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                dup[i] = true;
                dup[j] = true;
            }
        }
    }

    int max = -1;

    /* dup배열은 없어도 될거같았는데 정말 쉬운거였구나
    // 최댓값 찾기
    int max = -1;
    for(int i = 0; i < n; i++) {
        int curr_num = nums[i];
        // 최대가 될 수 있는 후보입니다.
        if(max < curr_num) {
            // 갱신할 수 있는지 확인하기 위해 이 숫자의 등장 빈도를 셉니다.
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] == curr_num) {
                    count++;
                }
            }
            // 이 숫자가 배열에서 유일할때만 갱신합니다.
            if(count == 1) {
                max = curr_num;
            }
        }
    }
    */

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max && !dup[i])
            max = arr[i];
    }

    cout << max;

    return 0;
}