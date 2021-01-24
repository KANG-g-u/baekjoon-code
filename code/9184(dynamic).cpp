#include<iostream>
#include<algorithm>
using namespace std;

int w[51][51][51];

int solve(int a,int b, int c){
	if(a <= 0 || b <= 0 || c <= 0){
		return 1;
	}
	
	if(w[a][b][c] == 0){
		if(a <= 0 || b <= 0 || c <= 0){
			return w[a][b][c] = 1;
		}
		else if(a > 20 || b > 20 || c > 20){
			return w[a][b][c] = solve(20,20,20);
		}
		else if(a < b && b < c){
			return w[a][b][c] = solve(a,b,c-1) + solve(a,b-1,c-1) - solve(a,b-1,c);
		}
		else{
			return w[a][b][c] = solve(a-1,b,c) + solve(a-1,b-1,c) + solve(a-1,b,c-1) - solve(a-1,b-1,c-1);
		}
	}
	else{
		return w[a][b][c];
	}
}

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	while(a != -1 || b != -1 || c != -1){
		printf("w(%d, %d, %d) = %d\n",a,b,c,solve(a,b,c));
		cin >> a >> b >> c;
	}
	return 0;
}
