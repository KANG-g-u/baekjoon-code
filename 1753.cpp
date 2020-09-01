#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 20001
#define INF 999999999
int V,E,K;
vector<pair<int, int> > v[MAX];
int dist[MAX];

void Dijkstra(){
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0,K));
	while(!pq.empty()){
		int cost= -pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		for(int i=0;i<v[cur].size();i++){
			int next_cost=v[cur][i].second;
			int next=v[cur][i].first;
			if(dist[next] > cost+next_cost){
				dist[next]=cost+next_cost;
				pq.push(make_pair(-dist[next],next));
			}
		}
	}
	for(int i=1;i<=V;i++){
		if(i==K)
			printf("0\n");
		else if(dist[i]==INF)
			printf("INF\n");
		else
			printf("%d\n",dist[i]);
	}
}

int main(){
	scanf("%d %d",&V,&E);
	scanf("%d",&K);
	for(int i=0;i<E;i++){
		int from,to,cost;
		scanf("%d %d %d",&from,&to,&cost);
		v[from].push_back(make_pair(to,cost));
	}
	for(int i=1;i<=V;i++)
		dist[i]=INF;
	
	Dijkstra();
	
}
