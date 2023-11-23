#include<bits/stdc++.h>
using namespace std;
//const int N = 100;

int matrixchain(int a[],int i,int j,vector<vector<int> > &dp){
	if(i==j)
		return 0;
		
	if(dp[i][j] != -1)
		return dp[i][j];
		
	dp[i][j] = INT_MAX;
	
	for(int k=i;k<j;k++){
		dp[i][j] = min(dp[i][j],matrixchain(a,i,k,dp) + matrixchain(a,k+1,j,dp) + (a[i-1]*a[k]*a[j]));
	}
	return dp[i][j];
}
int main(){
    //code here
    int n;
    cout<<"enter size of matrices: ";
	cin>>n;
	cout<<'\n';
	int a[n];
	cout<<"enter array: ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<'\n';
	
	vector<vector<int> > dp(n+1,vector<int> (n+1,-1));					
	int ans = matrixchain(a,1,n-1,dp);
	cout<<"best answer: "<<ans<<'\n';
	return 0;
}


