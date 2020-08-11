#include <iostream>

using namespace std;
class Runner
{
    public:
        int velocity;
        int rank;
        int pos;
        
    	void setRunner(int v,int r,int p);
};

void Runner::setRunner(int v,int r,int p){
	velocity=v;
	rank=r;
	pos=p;
}

Runner *runners, *temps;

void merge(int start, int mid, int end)
{
    int p1 = start;
    int p2 = mid+1;
    int k = start;
    while (p1 <= mid && p2 <= end)
    {
        if(runners[p1].velocity >= runners[p2].velocity)
        {
            temps[k++] = runners[p1++];
        }
        else
        {
        	temps[k] = runners[p2];
        	temps[k++].rank -=(p2++-k);
        }
    }
    while (p1 <= mid)
    {
        temps[k++] = runners[p1++];
    }
    while (p2 <= end)
    {
        temps[k++] = runners[p2++];
    }
    for (int i = start; i <= end; i++)
    {
        runners[i] = temps[i];
    }
}

void mergeSort(int start, int end)
{
    int mid = (start + end) / 2;
    if (start < end)
    {
        mergeSort(start, mid);
        mergeSort(mid+1, end);
        merge(start, mid, end);
    }
}

int main()
{
    int N, vel,*ranking;
	cin >> N;
    runners = new Runner[N];
    temps = new Runner[N];
    ranking = new int[N];
    for(int i = 0; i < N; i++)
    {
        cin >> vel;
        runners[i].setRunner(vel,i+1,i);
    }
    mergeSort(0, N-1);
    
    for(int i=0;i<N;i++)
    	ranking[runners[i].pos]=runners[i].rank;
    
    for (int i = 0; i < N; i++)
        cout << ranking[i] << "\n";
	delete ranking;
    delete runners;
    delete temps;
    return 0;
}
