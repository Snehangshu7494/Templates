#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays into one
void merge(vector<long long>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary vectors
    vector<long long> L(n1), R(n2);

    // Copy data to temp vectors
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the temp vectors back into arr
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy any remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive Merge Sort
void mergeSort(vector<long long>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort both halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge sorted halves
        merge(arr, left, mid, right);
    }
}

// Driver code
int main() {
    vector<long long> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    for (long long x : arr)
        cout << x << " ";
    cout << "\n";

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:   ";
    for (long long x : arr)
        cout << x << " ";
    cout << "\n";

    return 0;
}
