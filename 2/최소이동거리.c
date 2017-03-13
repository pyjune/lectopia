#include <stdio.h>
#include <stdlib.h>

int A[11][11]; // 인덱스 1~10까지 사용.. 
int used[10];
int p[10];
int arr[10];
int min; 
int cnt;
// 나무의 순서를 정하는 순열... 
void npr(int n, int k, int l);
// 나무를 추가할때마다 거리를 계산하는 함수.. 
void npr2(int n, int k, int l, int distance);

int main(int argc, char *argv[]) {
	
	int tc, T;
	int i, j;
	int N;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d", &N);
		min = 0x7fffffff;
		cnt=0;
		for(i=0;i<N-1;i++)
			arr[i]= i+2; // 나무번호 2~N까지를 배열에 저장.. 
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				scanf("%d", &A[i][j]);
			}
		}
		//npr(0, N-1, N-1);
		npr2(0, N-1, N-1, 0);
		printf("#%d %d %d\n", tc, min, cnt);
		
	}
	 
	
	
	return 0;
}
void npr2(int n, int k, int l, int distance)
{
	int i;
	int sum=0;
	if(n==k)
	{
		cnt++;

		distance +=A[p[l-1]][1]; // 마지막 나무->사무실 거리..
		if(min>distance)
			min = distance; 
	}
	else if(distance>=min)
		return;		
	else
	{
		for(i=0;i<l;i++)
		{
			if(used[i]==0)
			{
				used[i]=1;
				p[n] = arr[i]; // 나무 번호를 순열로 생성..
				// p[n]나무까지의 거리를 더해서 전달 
				if(n==0)
					npr2(n+1, k, l, A[1][p[n]]);
				else
					npr2(n+1, k, l, distance+A[p[n-1]][p[n]]);
				used[i]=0; 
			}
		}
	}
}
void npr(int n, int k, int l)
{
	int i;
	int sum=0;
	if(n==k)
	{
		cnt++;
		sum=A[1][p[0]]; // 사무실->첫번째 나무까지 거리..
		// 나무수 l, 마지막 나무 인덱스=l-1 
		// 마지막 나무 하나 전 나무 = l-2 
		for(i=0;i<=l-2;i++) 
			sum += A[p[i]][p[i+1]]; // p[i]->p[i+1]나무까지 거리
		sum +=A[p[i]][1]; // 마지막 나무->사무실 거리..
		if(min>sum)
			min = sum; 
	}
	else
	{
		for(i=0;i<l;i++)
		{
			if(used[i]==0)
			{
				used[i]=1;
				p[n] = arr[i]; // 나무 번호를 순열로 생성..
				npr(n+1, k, l);
				used[i]=0; 
			}
		}
	}
}
