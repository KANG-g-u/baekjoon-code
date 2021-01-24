#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 1000000
long long wood[MAX+1];

int main(){
	int N,M;
	long long wood_max=0;
	cin>> N >> M;
	for(int i=0;i<N;i++){
		cin>>wood[i];
		wood_max=max(wood_max,wood[i]);
	}
	long long end=wood_max;
	long long start=1;
	long long mid;
	long long result=0;
	while(start<=end){
		mid=(start+end)/2;
		long long sum=0;
		for(int i=0;i<N;i++){
			if(wood[i]>mid){
				sum+=wood[i];
				sum-=mid;
			}
		}
		if(sum>=M){
			if(result<mid)
				result=mid;
			start=mid+1;			
		}
		else{
			end=mid-1;
		}
	}
	cout<<result;
}
