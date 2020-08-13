#include<iostream>
using namespace std;

int GCD(int a,int b){
	if(a<b){
		int temp=a;
		a=b;
		b=temp;
	}
	while(b!=0){
		int r = a%b;
		a=b;
		b=r;
	}
	return a;
}

int main(){
	int a,b,c,d;
	scanf("%d %d",&a,&b);
	scanf("%d %d",&c,&d);
	int up=a*d + b*c;
	int down = b*d;
	
	int divisor=GCD(up,down);
	up /=divisor;
	down /=divisor;
	printf("%d %d\n",up,down);
	return 0;
}
