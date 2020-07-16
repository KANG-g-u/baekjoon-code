#include<iostream>
#include<cstdlib>
using namespace std;

char n[100001];
int count[10];

int main(){
	cin >> n;
	int j=0;
	int sum=0;
	int len=0;
	while(n[j]!='\0'){
		len++;
		sum+=n[j]-48;
		count[n[j]-48]++;
		j++;
	}
	
	if(sum%3 == 0 && count[0]>=1){
		for(int i=9;i>=0;i--){
			while(count[i]>0){
				printf("%d",i);
				count[i]--;
			}
		}
	}
	else
		printf("-1");
	return 0;
}
