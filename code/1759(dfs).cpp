#include<iostream>
#include<algorithm>
using namespace std;

int L,C;
char word[16];
char arr[16];
bool visited[16];
char vowel[5]={'a','e','i','o','u'};

bool checkPossible(char* arr,int cnt){
	int flag1=0;
	int flag2=0;
	for(int i=0;i<cnt;i++){
		for(int j=0;j<5;j++){
			if(vowel[j]==arr[i])
				flag1++;
		}
	}
	flag2=cnt-flag1;
	if(flag2>=2 && flag1>=1)
		return true;
	else
		return false;
}

void dfs(int index,int cnt){
	visited[index]=true;
	arr[cnt++]=word[index];
	
	if(cnt==L){
		if(checkPossible(arr,cnt))
			cout<<arr<<"\n";
	}
	else{
		for(int i=index+1;i<C;i++){
			if(visited[i]==false){
				dfs(i,cnt);
			}
		}
	}
	visited[index]=false;
}

int main(){
	cin>>L>>C;
	for(int i=0;i<C;i++){
		cin>>word[i];
	}
	
	sort(word,word+C);
	
	for(int i=0;i<=C-L;i++){
		dfs(i,0);
	}
	
}
