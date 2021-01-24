#include<iostream>
#include<cstring>
using namespace std;

int n;
int cnt_white;
int cnt_blue;
int square[129][129];

void quadtree(int tpl_x,int tpl_y,int btr_x,int btr_y){
	int check=square[tpl_x][tpl_y];
	
	for(int i=tpl_x;i<btr_x;i++){
		for(int j=tpl_y;j<btr_y;j++){
			if(check==0 && square[i][j]==1)
				check=2;
			else if(check==1 && square[i][j]==0)
				check=2;
			if(check==2){
				quadtree(tpl_x,tpl_y,(tpl_x+btr_x)/2,(tpl_y+btr_y)/2);
				quadtree(tpl_x,(tpl_y+btr_y)/2,(tpl_x+btr_x)/2,btr_y);
				quadtree((tpl_x+btr_x)/2,tpl_y,btr_x,(tpl_y+btr_y)/2);
				quadtree((tpl_x+btr_x)/2,(tpl_y+btr_y)/2,btr_x,btr_y);
				return ;
			}
		}
	}
	if(check==0)
		cnt_white++;
	else if(check==1)
		cnt_blue++;
	return;
}

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>square[i][j];
	
	quadtree(0,0,n,n);
	cout<<cnt_white<<endl;
	cout<<cnt_blue;	
	return 0;
}
