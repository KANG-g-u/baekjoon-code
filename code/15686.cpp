#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int N,M;
int result;
int city[51][51];
bool issued[14];
vector<pair<int,int> > home;
vector<pair<int,int> > chicken;

void dfs(int chickenNum,int chickenCnt){
	//치킨 지점의 수가 초과 
	if(chickenNum>chicken.size()) return;
	//M개의 치킨집이 정해지면
	if(chickenCnt==M){
		int close_ans=0;
		int temp=home.size();
		for(int i=0;i<temp;i++){
			int distance=101;
			int temp1=chicken.size();
			for(int j=0;j<temp1;j++){
				if(issued[j]){
					int home_y=home[i].first, home_x=home[i].second;
					int chicken_y=chicken[j].first, chicken_x=chicken[j].second;
					int temp2=abs(home_y-chicken_y)+abs(home_x-chicken_x);
					distance=min(distance,temp2);
				}
			}
			close_ans+=distance;
		}
		result=min(result,close_ans);
		return ;
	} 
	//치킨집 cnt지점 들릴
	issued[chickenNum]=true;
	dfs(chickenNum+1,chickenCnt+1);
	//치킨집 cnt지점 패스할때
	issued[chickenNum]=false;
	dfs(chickenNum+1,chickenCnt);
}

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>city[i][j];
			if(city[i][j]==1){
				home.push_back(make_pair(i,j));
			}
			else if(city[i][j]==2){
				chicken.push_back(make_pair(i,j));
			}
		}
	}
	result=1e9;
	dfs(0,0);
	cout<<result;
	return 0;
}
