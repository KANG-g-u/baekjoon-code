#include<iostream>
using namespace std;

#define MAX 100

int N;

int graph[MAX+1][MAX+1];
void FloydWarshall(){
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(graph[i][k] && graph[k][j])
					graph[i][j]=1;
				
			}
		}
	}
}

int main(){
	cin>>N;
	//graph �Է� 
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>graph[i][j];
	//�÷��̵�ͼ� �˰��� ���� 
	FloydWarshall(); 
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<"\n";
	}
}
