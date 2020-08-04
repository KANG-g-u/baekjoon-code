#include<iostream>
#include<queue>
using namespace std;

int lotto[50];
int cnt;
int arr[50];

void dfs(int start, int depth){
	
	if(depth==6){
		for(int i=0;i<6;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return ;
	}
	for(int i=start;i<cnt;i++){
		arr[depth]=lotto[i];
		dfs(i+1,depth+1);
	}
	
}

void initialize(){
	for(int i=0;i<cnt;i++){
		lotto[i]=0;
	}
	return;
}

int main(){
	cin>>cnt;
	while(cnt!=0){
		for(int i=0;i<cnt;i++){
			cin>>lotto[i];
		}
		dfs(0,0);
		cout<< "\n";
		initialize();
		cin>>cnt;
	}
	return 0;
}
