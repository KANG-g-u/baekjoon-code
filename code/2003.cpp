#include<iostream>
using namespace std;

#define MAX 10000
int A[MAX+1];

int main(){
	int cnt=0;
	int N, M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin>>A[i];
	int low=0;
	int high=0;
	int sum=0;
	while(1){
		if (sum >= M) 
			sum -= A[low++];
        else if (high == N) 
			break;
        else 
			sum += A[high++];
        if (sum == M) 
			cnt++;
	}
	cout<<cnt;
}
