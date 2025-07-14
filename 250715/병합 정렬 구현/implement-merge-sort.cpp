#include <iostream>

using namespace std;

int n;
int arr[100000];
int merged_arr[100000];

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            merged_arr[k++] = arr[i++];
        else
            merged_arr[k++] = arr[j++];
    }

    while (i <= mid)
        merged_arr[k++] = arr[i++];
    
    while (j <= high)
        merged_arr[k++] = arr[j++];
    
    for (int k = low; k <= high; k++)
        arr[k] = merged_arr[k];
}

void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}