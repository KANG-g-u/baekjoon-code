#include<iostream>
#include<stack> 
#include<algorithm>
using namespace std;

int N, M;
int max_result;
int board[51][51];
int result[51][51];
bool visited[51][51];
int my[4]={1,-1,0,0};
int mx[4]={0,0,-1,1};
int flag;

bool check(int y,int x){
	return y >= 0 && x >=0 && y < N && x < M;
}

int dfs(int y,int x){
	if(!check(y,x) || board[y][x]==0)
		return 0;
	if(visited[y][x]){
		printf("-1");
		exit(0);
	}
	if(result[y][x]!=0) return result[y][x];
	visited[y][x]=true;
	int score=board[y][x];
	for(int i=0;i<4;i++){
		int next_y=y+score*my[i];
		int next_x=x+score*mx[i];
		result[y][x]=max(result[y][x],dfs(next_y,next_x)+1);
	}
	visited[y][x]=false; 
	return result[y][x];
}


int main(){
	cin>>N>>M;
	char temp;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>temp;
			if(temp=='H')
				board[i][j]=0; // 구멍(H)은 0로 표시 
			else
				board[i][j]=temp-48;
		}
	}
	
	/*for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			//cout<<result[i][j]<<" ";
			max_result=max(result[i][j],max_result);
		}//cout<<"\n";
	}*/
	printf("%d\n",dfs(0,0));	
	return 0;
}
