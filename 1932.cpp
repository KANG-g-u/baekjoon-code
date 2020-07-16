#include<iostream>
#include<algorithm>
using namespace std;

int n;
int triangle[500][500];

int main(){
	cin >> n;
	
	int result=0;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			cin>>triangle[i][j];
	
	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			if(j>0)
				triangle[i][j]=max(triangle[i-1][j-1]+triangle[i][j],triangle[i-1][j]+triangle[i][j]);
			else
				triangle[i][j]=triangle[i-1][j]+triangle[i][j];
			
		}
	}
	
	for(int i=0;i<n;i++){
		if(result<triangle[n-1][i])
			result=triangle[n-1][i];
	}
	
	printf("%d",result);
	return 0;
}
