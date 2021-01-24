#include<iostream>
#include<algorithm>
using namespace std;

int N,K;
int w[101];
int v[101];
int dp[101][100001];

int knapsack(int k, int weight[],int value[],int n){
	if(n==0 || k==0)
		return 0;
	
	if(weight[n-1]>k)
		return knapsack(k,weight,value,n-1);
	else
		return max(value[n-1]+knapsack(k-weight[n-1],weight,value,n-1),
					 knapsack(k,weight,value,n-1));
}

int main(){
	cin>>N>>K;
	
	for(int i=0;i<N;i++){
		cin>>w[i];
		cin>>v[i];
	}
	
	for(int i=0;i<=N;i++){
		for(int j=0;j<=K;j++){
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(w[i-1]<=K && j>=w[i-1])
				dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
			
		}
	}
	
	cout<<dp[N][K];
	
	return 0;
}
