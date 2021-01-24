#include<iostream>
using namespace std;

int n;

int A[101];
int B[101];
int result[101];

int upper_BS(int *arr,int n,int key){
	int start=0;
	int end=n;
	int mid;
	while(end>start){
		mid=(start+end)/2;
		
		if(arr[mid]>=key){
			end=mid;
		}
		else{
			start=mid+1;
		}
	}
	return end;
}

int main(){
	cin>>n;
	int locate=0;
	int cnt=0;
	int min_idx=0;
	int temp=0;
	int flag=0;
	int temp1,temp2;
	
	for(int i=0;i<n;i++)
		cin >> A[i] >> B[i];
		
	for(int i=0;i<n-1;i++){
		temp=A[i];
		for(int j=i+1;j<n;j++){
			if(temp>A[j]){
				flag=1;
				temp=A[j];
				min_idx=j;
			}
		}
		if(flag==1){
		temp1=A[i];
		temp2=B[i];
		A[i]=A[min_idx];
		B[i]=B[min_idx];
		A[min_idx]=temp1;
		B[min_idx]=temp2;
		}
		flag=0;
	}
	
	for(int i=0;i<n;i++){
		if(result[cnt]<B[i])
			result[++cnt]=B[i];
		else{
			locate=upper_BS(result,cnt,B[i]);
			result[locate]=B[i];
		}
	}
	
	printf("%d",n-cnt);
	
}

