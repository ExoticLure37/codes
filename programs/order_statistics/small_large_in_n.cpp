#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={13,12,6,7,2,1};
    int n=sizeof(a)/sizeof(a[0]);
    int min,max;
    if(a[1]<a[2]){
        min=a[1];
        max=a[2];
    }
    else{
        min=a[2];
        max=a[1];
    }
    for(int i=3;i<n;i+=2){
        if(a[i]<a[i+1]){
            if(a[i]<min){
                min=a[i];
            }
            else if(a[i+1]>max){
                max=a[i+1];
            }
        }
        else{
            if(a[i+1]<min){
                min=a[i+1];
            }
            else if(a[i]>max){
                max=a[i];
            }
        }
    }
    cout<<"Largest element is "<<max<<endl;
    cout<<"Smallest element is "<<min<<endl;
    return 0;
}