#include<iostream>
#include<algorithm>
using namespace std;

int n;
int num[100001];
int dp[100001];
int result=-99999;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>> num[i];
	}
	
	for(int i=0;i<n;i++){
		dp[i]=num[i];
		if(i==0){
			result=dp[i];
			continue;
		}
		else{
			dp[i]=max(dp[i-1]+dp[i],dp[i]);
		}
		if(dp[i]>result)
			result=dp[i];
	}
	cout<<result;
	return 0;
}
