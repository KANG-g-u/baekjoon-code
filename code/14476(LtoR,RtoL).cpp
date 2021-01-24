#include<iostream>
#include<algorithm>
using namespace std;

int GCD(int a,int b){
	if(a<b){
		int temp=a;
		a=b;
		b=temp;
	}
	while(b!=0){
		int r = a%b;
		a=b;
		b=r;
	}
	return a;
}

bool divisor(int a,int b){
	if(a>b)
		return false;
	else{
		if(b%a==0)
			return true;
		else
			 return false;
	}
}

int main(){
	int n;
	cin>>n;
	int max_gcd=0;
	int remove=0;
	int* arr,*LtoR,*RtoL;
	arr = new int[n];
	LtoR = new int[n];
	RtoL = new int[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	LtoR[0]=arr[0]; RtoL[n-1]=arr[n-1];
	for(int j=1;j<n;j++){
		LtoR[j]=GCD(LtoR[j-1],arr[j]);
	}
	for(int k=n-2;k>=0;k--){
		RtoL[k]=GCD(RtoL[k+1],arr[k]);
	}
	for(int i=0;i<n;i++){
		int temp=0;
		if(i==0){
			temp=RtoL[1];
		}
		else if(i==n-1){
			temp=LtoR[n-2];
		}
		else{
			temp=GCD(LtoR[i-1],RtoL[i+1]);
		}
		if(temp>max_gcd){
			int check=arr[i];
			if(!divisor(temp,check)){
				max_gcd=temp;
				remove=arr[i];
			}
		}
	}
	if(remove==0)
		printf("-1\n");
	else
		printf("%d %d\n",max_gcd,remove);
	return 0;
}
