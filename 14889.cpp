#include<iostream>
#include<algorithm>
using namespace std;

int A[21][21];
int n;
int mid;
int b[11];

int start,link;
int result=99999;

void func1(int *a,bool *issued){
	int k=0;
	for(int i=0;i<n;i++){
		if(!issued[i])
			b[k++]=i;
	}
	int first,second,third,fourth;
	int temp;
	for(int i=0;i<mid-1;i++){
		first=a[i];
		third=b[i];
		for(int j=i+1;j<mid;j++){
			second=a[j];
			fourth=b[j];
			start+=A[first][second];
			start+=A[second][first];
			link+=A[third][fourth];
			link+=A[fourth][third];
		}
	}
		temp=start-link;
			if(temp<0)
				temp=-temp;
			result=min(temp,result);
		start=0;
		link=0;
}

void func(int *a,bool *issued,int k){
	if(k==mid){
		func1(a,issued);
		return;
	}
	else{
		for(int i=k;i<n;i++){
			if(!issued[i]){
				if(k==0)
				{
			a[k]=i;
			if(a[0]==mid)
				return;
			issued[i]=true;
			func(a,issued,k+1);
			issued[i]=0;
				}
				else if(i>a[k-1]){
					a[k]=i;
					issued[i]=true;
					func(a,issued,k+1);
					issued[i]=0;
				}
				
			}
		}
	}
}


int main(){
	cin>>n;
	mid=n/2;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>A[i][j];
	int a[11]={};
	bool issued[20]={};
	func(a,issued,0);
	
	printf("%d",result);
}
