#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string word[10];
int word_cnt[26];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int N;
	cin>>N;
	int result=0;
	for(int i=0;i<N;i++){
		cin>>word[i];
	}
	for(int i=0;i<N;i++){
		int len=word[i].length();
		int size=1;
		for(int j=len-1;j>=0;j--){
			word_cnt[word[i][j]-'A']+=size;
			size*=10;
		}
	}
	sort(word_cnt,word_cnt+26,cmp);
	int word_num=9;//Å«¼öºÎÅÍ 9 
	for(int i=0;i<9;i++){
		//printf("%d  ",word_cnt[i]);
		result=result+word_cnt[i]*word_num;
		word_num--;
	}
	printf("%d",result);
		
}
