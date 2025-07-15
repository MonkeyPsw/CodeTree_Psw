#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];

/*
int SelectPivot(int low, int high)
{
    int a = arr[low], b = arr[high], c = arr[(low + high) / 2];

    if ((a <= b && b <= c) || (c <= b && b <= a))
        return b;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return a;
    else
        return c;
}
*/

int Partition(int low, int high)
{
    //int pivot = SelectPivot(low, high);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void QuickSort(int low, int high)
{
    if (low < high)
    {
        int pos = Partition(low, high);

        QuickSort(low, pos - 1);
        QuickSort(pos + 1, high);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    QuickSort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
