#include<iostream>
#include<queue>
using namespace std;

int main(){
	priority_queue<int> max_pq;
	priority_queue<int ,vector<int> ,greater<int> > min_pq;
	int n;
	cin>>n;
	int temp;
	int comp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(i==0){
			max_pq.push(temp);
		}
		else{
			comp=max_pq.top();
		//MaxHeap�� ���� ū ���� minheap���� ���� ���� maxheap���� 
			if(temp>comp){
				min_pq.push(temp);
			}
			else{
				max_pq.push(temp);
			}
		}
		//������ ��
		int sizeMaxHeap=max_pq.size();
		int sizeMinHeap=min_pq.size(); 
		if(sizeMaxHeap==sizeMinHeap){//ũ�Ⱑ ������ maxheap�� 
			printf("%d\n",max_pq.top()); 
		}
		else if(sizeMaxHeap-sizeMinHeap==1){
			printf("%d\n",max_pq.top()); 
		}
		else if(sizeMinHeap-sizeMaxHeap==1){
			printf("%d\n",min_pq.top()); 
		}
		else if(sizeMaxHeap-sizeMinHeap>1){
			int mov=max_pq.top();
			max_pq.pop();
			min_pq.push(mov);
			printf("%d\n",max_pq.top()); 
		}
		else if(sizeMinHeap-sizeMaxHeap>1){
			int mov=min_pq.top();
			min_pq.pop();
			max_pq.push(mov);
			printf("%d\n",max_pq.top()); 
		}
	}
	return 0;
}
