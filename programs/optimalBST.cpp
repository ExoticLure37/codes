#include<bits/stdc++.h>
using namespace std;
//const int N = 100;

int optimalBST(int freq[],int i,int j,vector<vector<int> > &dp){
	if(i>j)
		return 0;
		
	if(dp[i][j] != -1)
		return dp[i][j];
		
	dp[i][j] = INT_MAX;
	for(int r=i;r<=j;r++){
		int left = optimalBST(freq,i,r-1,dp);
		int right = optimalBST(freq,r+1,j,dp);
		dp[i][j] = min(dp[i][j],left+right);
	}
	
	for(int k=i;k<=j;k++){
		dp[i][j] += freq[k];
	}
	return dp[i][j];
}

int main(){
    //code here
    int n;
    cout<<"enter size of array: ";
	cin>>n;
	cout<<'\n';
	int keys[n],freq[n];
	cout<<"enter key array: ";
	for(int i=0;i<n;i++){
		cin>>keys[i];
	}
	cout<<'\n';
	cout<<"enter frq array: ";
	for(int i=0;i<n;i++){
		cin>>freq[i];
	}
	cout<<'\n';
		
	vector<vector<int> > dp(n+1,vector<int> (n+1,-1));					
	int ans = optimalBST(freq,0,n-1,dp);
	cout<<"best answer: "<<ans<<'\n';
	return 0;
}


