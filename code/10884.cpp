#include<iostream>
using namespace std;

int count[10];
int cnt[10];
int n;

void solve(int n){
	int temp=0;\
	
	if(n==1){
		count[0]=0;
		for(int i=1;i<=9;i++)
			count[i]++;
	}
	else{
		for(int i=0;i<=9;i++){
			if(i==0){
				temp=count[0];
				count[0]=0;
				cnt[1]+=temp;
				if(cnt[1]>=1000000000)
					cnt[1]%=1000000000;
			}
			else if(i==9){
				temp=count[9];
				count[9]=0;
				cnt[8]+=temp;
				if(cnt[8]>=1000000000)
					cnt[8]%=1000000000;
			}
			else{
				temp=count[i];
				count[i]=0;
				cnt[i-1]+=temp;
				if(cnt[i-1]>=1000000000)
					cnt[i-1]%=1000000000;
				cnt[i+1]+=temp;
				if(cnt[i+1]>=1000000000)
					cnt[i+1]%=1000000000;
			}
		}
		for(int i=0;i<=9;i++){
		count[i]=cnt[i];
		cnt[i]=0;
	}
	}
	
	
	
}

int main(){
	cin>>n;
	int sum=0;
	
	for(int i=1;i<=n;i++)
		solve(i);
	
	
	
	for(int i=0;i<=9;i++){
		sum+=count[i];
		if(sum>=1000000000)
			sum%=1000000000;
	}
	printf("%d",sum);
	return 0;
}
