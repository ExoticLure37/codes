#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
int rpartition(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}
void RQS(int arr[], int low, int high)
{
    if (low < high) {
        int pi = rpartition(arr, low, high);
        RQS(arr, low, pi - 1);
        RQS(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout<<arr[i]<<" "; 
}
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    RQS(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}