#include<iostream>
#include<queue>
using namespace std;

int main(){
	priority_queue<int> pq;
	int n;
	cin>>n;
	
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(temp==0){
			if(pq.empty())
				printf("0\n");
			else{
				printf("%d\n",pq.top());
				pq.pop();
			}
		}
		else{
			pq.push(temp);
		}
	}
	return 0;
}
