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
int ith_order(int arr[],int low,int high,int i){
    if(low<high){
        int q=rpartition(arr,low,high);
        int k=q-low+1;
        if(i==k){
            return arr[q];
        }
        else if(i<k){
            return ith_order(arr,low,q-1,i);
        }
        else{
            return ith_order(arr,q+1,high,i-k);
        }
    }
}
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int z=ith_order(arr,0,n-1,3);
    cout<<"Third smallest element is "<<z<<endl;
    return 0;
}