#include<iostream>
#include<cstring>
using namespace std;

int n;
int cnt_zero;
int cnt_plus;
int cnt_minus;
short square[2188][2188];

void ninetree(int tpl_x,int tpl_y,int btr_x,int btr_y){
	int check=square[tpl_x][tpl_y];
	
	for(int i=tpl_x;i<btr_x;i++){
		for(int j=tpl_y;j<btr_y;j++){
			if(check==0 && square[i][j] != 0)
				check=2;
			else if(check==1 && square[i][j]!=1)
				check=2;
			else if(check==-1 && square[i][j]!=-1)
				check=2;
			if(check==2){
				ninetree(tpl_x,tpl_y,tpl_x+(btr_x-tpl_x)/3,tpl_y+(btr_y-tpl_y)/3);//1
				ninetree(tpl_x,tpl_y+(btr_y-tpl_y)/3,tpl_x+(btr_x-tpl_x)/3,tpl_y+(btr_y-tpl_y)*2/3);//2
				ninetree(tpl_x,tpl_y+(btr_y-tpl_y)*2/3,tpl_x+(btr_x-tpl_x)/3,btr_y);//3
				ninetree(tpl_x+(btr_x-tpl_x)/3,tpl_y,tpl_x+(btr_x-tpl_x)*2/3,tpl_y+(btr_y-tpl_y)/3);//4
				ninetree(tpl_x+(btr_x-tpl_x)/3,tpl_y+(btr_y-tpl_y)/3,tpl_x+(btr_x-tpl_x)*2/3,tpl_y+(btr_y-tpl_y)*2/3);//5
				ninetree(tpl_x+(btr_x-tpl_x)/3,tpl_y+(btr_y-tpl_y)*2/3,tpl_x+(btr_x-tpl_x)*2/3,btr_y);//6
				ninetree(tpl_x+(btr_x-tpl_x)*2/3,tpl_y,btr_x,tpl_y+(btr_y-tpl_y)/3);//7
				ninetree(tpl_x+(btr_x-tpl_x)*2/3,tpl_y+(btr_y-tpl_y)/3,btr_x,tpl_y+(btr_y-tpl_y)*2/3);//8
				ninetree(tpl_x+(btr_x-tpl_x)*2/3,tpl_y+(btr_y-tpl_y)*2/3,btr_x,btr_y);//9
				return ;
			}
		}
	}
	if(check==0)
		cnt_zero++;
	else if(check==1)
		cnt_plus++;
	else if(check==-1)
		cnt_minus++;

	return;
}

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>square[i][j];
	
	ninetree(0,0,n,n);
	
	cout<<cnt_minus<<endl;
	cout<<cnt_zero<<endl;
	cout<<cnt_plus;
	return 0;
}
