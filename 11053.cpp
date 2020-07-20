#include<iostream>
#include<fstream>
using namespace std;

int A[1001];
int result[1001];

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
    int n;
    int cnt=0;
    int locate;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>A[i];
		if(result[cnt]<A[i])
			result[++cnt]=A[i];
		else{
			locate=upper_BS(result,cnt,A[i]);
			result[locate]=A[i];
		}
	}
	
	printf("%d",cnt);
    
    return 0;
}
