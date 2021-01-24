#include<iostream>
#include<cstring>
using namespace std;

int n;
string square[65];

void quadtree(int tpl_x,int tpl_y,int btr_x,int btr_y){
	int check=square[tpl_x][tpl_y];
	
	for(int i=tpl_x;i<btr_x;i++){
		for(int j=tpl_y;j<btr_y;j++){
			if(check==48 && square[i][j]==49)
				check=2;
			else if(check==49 && square[i][j]==48)
				check=2;
			if(check==2){
				printf("(");
				quadtree(tpl_x,tpl_y,(tpl_x+btr_x)/2,(tpl_y+btr_y)/2);
				quadtree(tpl_x,(tpl_y+btr_y)/2,(tpl_x+btr_x)/2,btr_y);
				quadtree((tpl_x+btr_x)/2,tpl_y,btr_x,(tpl_y+btr_y)/2);
				quadtree((tpl_x+btr_x)/2,(tpl_y+btr_y)/2,btr_x,btr_y);
				printf(")");
				return ;
			}
		}
	}
	if(check==48){
		printf("0");
	}
	else if(check==49){
		printf("1");
	}
	return;
}

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>square[i];
	
	quadtree(0,0,n,n);
	return 0;
}
