#include <iostream>
using namespace std;

void merge(int arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int leftArr[n1];
    int rightArr[n2];
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[m + 1 + j];
    int i = 0;  
    int j = 0;  
    int k = l;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int i=0;i<6;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, 5);

    cout << "Sorted array: ";
    for (int i=0;i<6;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
