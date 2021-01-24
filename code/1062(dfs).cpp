#include<iostream>
#include<cstring>
using namespace std;

int N, K;

bool visited[26];
string word[51];
int selectedCount;
int result;

int countWords(){
	int count=0;
	for(int i=0;i<N;i++){
		int temp=0;
		int len=word[i].length();
		for(int j=0;j<len;j++){
			if(!visited[word[i][j]-97]){
				temp=1;
				break;
			}
		}
		if(temp==0)
			count++;
	}
	return count;
}

void step1(){
	visited['a'-'a']=true;
	visited['n'-'a']=true;
	visited['t'-'a']=true;
	visited['i'-'a']=true;
	visited['c'-'a']=true;
	selectedCount=5;
}

void dfs(int index){
//	1. 체크인                                visited[0-25] = { a, ... , z}
	visited[index]=true;
	selectedCount++;
//	2. 목적지인가?                         selectCount ==  K -> 최대개수 계산
	if(selectedCount==K){
		result=max(countWords(),result);
	}
	else{
		//	3. 갈 수 있는 곳을 순회              for( 0 ~ 25)
		for(int i=index+1;i<26;i++){
			//	4. 갈수있는가?                                if(visited[] ==false)
			if(visited[i]==false){
				//	5. 간다 DFS(NEXT)                                dfs(next)
				dfs(i);
			}
		}
	}
	//	6. 체크아웃                             visited[] = false
	visited[index]=false;
	selectedCount--;
}

int main(){
	cin>>N >> K;
	for(int i=0;i<N;i++)
		cin>>word[i];
		
	step1();
	
	for(int i=0;i<N;i++){
		word[i]=word[i].substr(4);
		int len=word[i].length();
		word[i].erase(len-4,len);
	}
	result=countWords();
	
	if(K>=5){
	for(int i=0;i<26;i++){
		if(visited[i]==false)
			dfs(i);
	}
	}
	else{
		result=0;
	}
	cout<<result;
	return 0;
}
