#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;

ll road[100001];
ll cost[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int numOfcities;
	ll result = 0;
	
	cin >> numOfcities;
	
	for(int i=0; i < numOfcities-1; i++){
		cin >> road[i];
	}
	cin >> cost[0];
	
	for(int i=1; i < numOfcities; i++){
		cin >> cost[i];
		if(cost[i-1] < cost[i]){
			cost[i]= cost[i-1];
		}
	}
	for(int i=0; i < numOfcities-1; i++){
		result += road[i] * cost[i];
	}
	cout << result;
	
	return 0;
	
}
