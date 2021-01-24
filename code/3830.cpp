#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 100001
typedef long long ll;

int parent[MAX];
vector<int> v[MAX];
ll diff[MAX];

int find(int a){
	if(parent[a]==a) return a;
	else {
		int temp=parent[a];
		parent[a]=find(parent[a]);
		diff[a]+=diff[temp];
		return parent[a];
	}
}

void Union(int a,int b,int c){
	if(a<b){
		int temp=a;
		a=b;
		b=temp;
		c=-c;
	}
	find(a); find(b);
	ll x=diff[b]; ll y=diff[a];
	a=find(a); b=find(b);
	parent[b]=a; diff[b]=c+y-x;
}


int main(){
	cin.tie(0);
	int N,M;
	while(true){
		scanf("%d %d",&N,&M);
		if(!N && !M)
			break; 
		for(int i=1;i<=N;i++){
			parent[i]=i;
			diff[i]=0;
			v[i].clear();
		}
		for(int i=0;i<M;i++){
			char command;
			cin>>command;
			if(command=='!'){
				int a,b,c;
				scanf("%d %d %d",&a,&b,&c);
				Union(a,b,c);
			}
			else{
				int a,b;
				scanf("%d %d",&a,&b);
				if(find(a)==find(b)){
					printf("%d\n",diff[b]-diff[a]);
				}
				else{
					printf("UNKNOWN\n");
				}
				
			}
		}
		
	}
	return 0;
}
