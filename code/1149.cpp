#include<iostream>
#include<algorithm>
using namespace std;

int n;
int RGB[1000][3];

int main(){
	cin>>n;
	int result=99999999;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			cin>>RGB[i][j]; 
	
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++){
			if(j==0){
				RGB[i][j]=min(RGB[i][j]+RGB[i-1][j+1],RGB[i][j]+RGB[i-1][j+2]);
			}
			else if(j==2){
				RGB[i][j]=min(RGB[i][j]+RGB[i-1][j-1],RGB[i][j]+RGB[i-1][j-2]);
			}
			else{
				RGB[i][j]=min(RGB[i][j]+RGB[i-1][j-1],RGB[i][j]+RGB[i-1][j+1]);
			}
		}
	
	for(int i=0;i<3;i++){
		if(result>RGB[n-1][i])
			result=RGB[n-1][i];
	}
	printf("%d",result);
	
	return 0;
}
