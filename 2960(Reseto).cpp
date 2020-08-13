#include<iostream>
using namespace std;

bool Reseto[1001];

void solve(int n,int k){
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(Reseto[i]==false){
			Reseto[i]=true;
			cnt++;
			if(cnt==k){
				printf("%d",i);
				return;
			}
		}
		else
			continue;
		int temp=i;
		for(int j=2;j*i<=n;j++){
			if(Reseto[temp*j]==false){
				Reseto[temp*j]=true;
				cnt++;
				if(cnt==k){
					printf("%d",temp*j);
					return;
				}
			}
		}
	}
}

int main(){
	int N, K;
	cin>>N>>K;
	
	solve(N,K);
	return 0;
}
