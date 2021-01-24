#include<iostream>
using namespace std;

int N,M,K;

int main(){
	cin>> N >> M >> K;
	while(K>0){
		if(N > 2*M){
			N--;
			K--;
		}
		else{
			M--;
			K--;
		}
	}
	int result;
	if(N>2*M)
		result=M;
	else
		result=N/2;
	printf("%d",result);
}
