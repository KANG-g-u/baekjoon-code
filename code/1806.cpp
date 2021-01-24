#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100000
int A[MAX+1];

int main(){
	int result=MAX;
	int N, S;
	cin >> N >> S;
	for(int i=0;i<N;i++)
		cin>>A[i];
	int low=0;
	int high=0;
	int sum=A[0];
	int flag=0;
	while(high<N){
		if (sum >= S) {
			flag=1;
			int len=high-low+1;
			result=min(len,result);
			sum -= A[low++];	
		}
        else {
			sum += A[++high];
		}
		
	}
	if(flag==0)
		cout<<"0";
	else
		cout<<result;
}
