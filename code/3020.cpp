#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 500000

int counting1[MAX+1];
int counting2[MAX+1];
int main(){
	
	int n,h;
	scanf("%d %d",&n,&h);
	int up,down;
	int check=0;
	
	for(int i=0;i<n;i+=2){
		scanf("%d",&up);
		scanf("%d",&down);
		counting1[up]++;
		counting2[h-down+1]++;
	}
	
	for(int i=h-1;i>=1;i--){
		counting1[i]+=counting1[i+1];
	}
	for(int i=2;i<=h;i++){
		counting2[i]+=counting2[i-1];
	}
	
	for(int i=1;i<=h;i++)
		counting1[i]+=counting2[i];
		
	sort(counting1+1,counting1+h+1);
	check=counting1[1];
	int result=1;
	int cnt=2;
	while(1){
		if(counting1[cnt++]==check)
			result++;
		else if(result>=h)
			break;
		else 
			break;
	}
	printf("%d %d",check,result);
	return 0;
}
