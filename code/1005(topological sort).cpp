#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int cost[1001];
int inDegree[1001];
vector<int> town[1001];
int result_time[1001];


void Topological_sort(int n){
	queue<int> q;
	
	for(int i=1; i<=n; i++){
		if(inDegree[i]==0){
			q.push(i);
			result_time[i] = cost[i];
		}
	}	
	
	for(int i=1; i<=n; i++){
		if(q.empty()){
			cout<< "cycle\n";
			return ;
		}
		int temp = q.front();
		q.pop();
		
		for(int j=0; j<town[temp].size(); j++){
			int x = town[temp][j];
			inDegree[x]--;
			result_time[x] = max(result_time[x], cost[x] + result_time[temp]);
			if(inDegree[x] == 0){
				q.push(x);
			}
		}
	}
}

int main(){
	int testcase;
	cin >> testcase;
	for(int t=0; t<testcase; t++){
		int numOftown;
		int ruleOftown;
		int src,dst;
		cin >> numOftown >> ruleOftown;
		int finalStructure;

		for(int i=1; i<=numOftown; i++){
			cin >> cost[i];
		}
		for(int j=0; j<ruleOftown; j++){
			cin >> src >> dst;
			inDegree[dst]++;
			town[src].push_back(dst);
		}
		cin >> finalStructure;
		Topological_sort(numOftown);
		cout << result_time[finalStructure] << "\n";
		for(int i=0; i<1000; i++){
			result_time[i]=0;
			cost[i]=0;
			town[i].clear();
			inDegree[i]=0;
		}
	}
	return 0;
}
