#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 10001
vector<int> v[MAX];
bool cut[MAX];
int numbering[MAX];
int number;
int V,E;

int dfs(int cur,bool isRoot){
	numbering[cur]= ++number;
	int ret=numbering[cur];
	
	int child=0;
	
	for(int i=0;i<v[cur].size();i++){
		int next=v[cur][i];
		
		if(numbering[next]){
			ret=min(ret,numbering[next]);
			continue;
		}
		child++;
		int prev=dfs(next,false);
		
		if(!isRoot && prev>=numbering[cur]){
			cut[cur]=true;
		}
		ret=min(ret,prev); // ´Ù½Ã ¿ø·¡ ¹æ¹®¹øÈ£·Î 
	}
	if(isRoot && child>=2){
		cut[cur]=true;
	}
	return ret;
}

int main(){
	int result=0;
	scanf("%d %d",&V,&E);
	int from,to;
	for(int i=0;i<E;i++){
		scanf("%d %d",&from,&to);
		v[from].push_back(to);
		v[to].push_back(from);
	}
	for(int i=1;i<=V;i++){
		if(!numbering[i]){
			dfs(i,true);
		}
	}
	for(int i=1;i<=V;i++){
		if(cut[i])
			result++;
	}
	printf("%d\n",result);
	for(int i=1;i<=V;i++){
		if(cut[i])
			printf("%d ",i);
	}
	return 0; 
}
