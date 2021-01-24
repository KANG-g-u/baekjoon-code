#include<iostream>
using namespace std;

int A[1001];
int B[1001];
int result[1001];
int result_pos[1001];
int result1[1001];
int result1_pos[1001];

int upper_BS(int *arr,int endpoint,int key){
	int start=0;
	int end=endpoint;
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

int lower_BS(int *arr,int n,int key){
	int start=0;
	int end=n;
	int mid;
	while(end>start){
		mid=(start+end)/2;
		
		if(arr[mid]<key){
			start=mid+1;
		}
		else{
			end=mid;
		}
	}
	return start;
}

int main(){
    int n;
    int cnt=0;
    int cnt1=0;
    int locate=0;
    int last_locate=0;
	int max=0;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>A[i];
		if(result[cnt]<A[i]){
			result[++cnt]=A[i];
		}
		else{
			locate=upper_BS(result,cnt,A[i]);
			result[locate]=A[i];
		}
		result_pos[i]=cnt;
	}
	
	for(int j=n-1; j>=0; j--){
		if(result1[cnt1]<A[j]){
			result1[++cnt1]=A[j];
		}
		else{
			locate=lower_BS(result1,cnt1,A[j]);
			result1[locate]=A[j];
		}
		result1_pos[j]=cnt1;
	}
	for(int i=0;i<n;i++){
		result_pos[i] = result_pos[i] + result1_pos[i];
		if(max < result_pos[i]){
			max = result_pos[i];
		}
	}
	
	printf("%d",max-1);
    
    return 0;
}
