#include<iostream>
using namespace std;

int A[101];

int gcd(int a,int b){
	int temp,n;
	
	if(a<b){
		temp=a;
		a=b;
		b=temp;
	}
	
	while(b!=0){
		n=a%b;
		a=b;
		b=n;
	}
	return a;
}

int main(){
	int n;
	cin >>n;
	int div;
	for(int i=0;i<n;i++){
		cin>>A[i];		
	}	
	for(int i=1;i<n;i++){
		div=gcd(A[0],A[i]);
		printf("%d/%d\n",A[0]/div,A[i]/div);	
	}
	return 0;
}
