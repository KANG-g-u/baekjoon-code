#include<iostream>
#include<cstring>
#include<stack>
#include<cmath>
using namespace std;

typedef long long ll;
stack<ll> s;
char command[100001][4];
int num[100001];

int main(){
	int T;
	ll result=0;
	int i=0, j=0, cnt=0,num_cnt=0;
	//명령어 받기 
	while(1){
		while(1){
		cin>>command[i];
		cnt++;
		if(!strcmp(command[i],"END"))
			break;
		else if(!strcmp(command[i],"NUM")){
			cin>>num[j++];
		}
		else if(!strcmp(command[i],"QUIT")){
			return 0;
		}
		i++;
	}
	cnt--;//END 명령어 빼주기 
	cin>>T;
	ll temp;
	for(int k=0;k<T;k++){
		while(!s.empty()){
			s.pop();
		}
		cin>>temp;
		s.push(temp);
		int error_check=0;
		for(int i=0;i<cnt;i++){
			//printf(":%s :%d::\n",command[i],s.top());
			ll temp1,temp2;
			if(!strcmp(command[i],"NUM")){
				s.push(num[num_cnt++]);
			}
			else if(!strcmp(command[i],"POP")){
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					s.pop();
				}
			}
			else if(!strcmp(command[i],"INV")){
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp1=s.top();
					temp1= -temp1;
					s.pop();
					s.push(temp1);
				}
			}
			else if(!strcmp(command[i],"DUP")){
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp1=s.top();
					s.push(temp1);
				}
			}
			else if(!strcmp(command[i],"SWP")){
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp1=s.top();
					s.pop();
				}
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp2=s.top();
					s.pop();
				}
				s.push(temp1);
				s.push(temp2);
			}
			else if(!strcmp(command[i],"ADD")){
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp1=s.top();
					s.pop();
				}
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
				}
				else{
					temp2=s.top();
					s.pop();
				}
				temp1+=temp2;
				if(abs(temp1)>1e9){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					s.push(temp1);
				}
			}
			else if(!strcmp(command[i],"SUB")){
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp1=s.top();
					s.pop();
				}
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp2=s.top();
					s.pop();
				}
				temp2-=temp1;
				if(abs(temp2)<=1e9){
					s.push(temp2);
				}
				else{
					printf("ERROR\n");
					error_check=1;
					break;
				}
			}
			else if(!strcmp(command[i],"MUL")){
				if(s.empty()){
					error_check=1;
					printf("ERROR\n");
					break;
				}
				else{
					temp1=s.top();
					s.pop();
				}
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp2=s.top();
					s.pop();
				}
				temp1*=temp2;
				if(abs(temp1)>1e9){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					s.push(temp1);
				}
			}
			else if(!strcmp(command[i],"DIV")){
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp1=s.top();
					s.pop();
				}
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp2=s.top();
					s.pop();
				}
				if(temp1==0){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp2/=temp1;
					s.push(temp2);
				}
			}
			else if(!strcmp(command[i],"MOD")){
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp1=s.top();
					s.pop();
				}
				if(s.empty()){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				else{
					temp2=s.top();
					s.pop();
				}
				if(temp1==0){
					printf("ERROR\n");
					error_check=1;
					break;
				}
				if(temp2<0){
					temp2%=temp1;
					s.push(-abs(temp2));
				}
				else{
					temp2%=temp1;
					s.push(abs(temp2));
				}
			}
		}
	if(!s.empty()){
		result=s.top();
		s.pop();
		if(s.empty() && error_check==0){
			printf("%d\n",result);
		}
		else{
			if(error_check==0)
				printf("ERROR\n");
		}
	}
	else{
		if(error_check==0)
			printf("ERROR\n");
	}
	error_check=0;
	num_cnt=0;
	}
	i=0, j=0, cnt=0;
	printf("\n");
}
	return 0;
}
