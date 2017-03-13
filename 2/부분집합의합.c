#include <stdio.h>
#include <stdlib.h>
/* 입력.. 
2
10 7
10 53
*/

int A[100];
int L[100]; // 1, 0으로 부분집합 표시.. 
int N, S;
int cnt;
int cnt2; 
void subset(int n, int k);
void subset1(int n, int k);
void subset2(int n, int k, int ssum);
void subset3(int n, int k, int ssum,int tsum);
int main(int argc, char *argv[]) {

	int tc, T;
	int i;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	
	for(i=0;i<100;i++)
	{
		A[i] = i+1;
	}
	for(tc = 1; tc<=T;tc++)
	{
		scanf("%d %d", &N, &S);
		cnt = 0;
		cnt2 = 0;
		for(i=0;i<N;i++)
		{
			L[i] = 0;
		}
		//subset(0, N);
		//subset1(0, N);
		//subset2(0, N, 0);
		subset3(0, N, 0, (1+N)*N/2);
		printf("#%d %d %d\n", tc, cnt, cnt2);	
	}
	return 0;
}
// 고려한 구간과 남은 구간의 합을 이용... 
void subset3(int n, int k, int ssum, int tsum)
{
	int i;
	 
	if(n==k)
	{
		cnt2++; // 부분집합의 완성 횟수 기록.. 
		
		if(ssum==S)
			cnt++;
		
	}
	else if(ssum > S)
	{
		return;
	}
	else if((ssum+tsum)<S)
	{
		return;
	}
	else
	{
		L[n] = 0;
		subset3(n+1, k, ssum, tsum-A[n]);
		L[n] = 1;
		subset3(n+1, k, ssum+A[n], tsum-A[n]);
	}
}
// 고려한 구간의 합을 비교.. 
void subset2(int n, int k, int ssum)
{
	int i;
	 
	if(n==k)
	{
		cnt2++; // 부분집합의 완성 횟수 기록.. 
		
		if(ssum==S)
			cnt++;
		
	}
	else if(ssum > S)
	{
		return;
	}
	else
	{
		L[n] = 0;
		subset2(n+1, k, ssum);
		L[n] = 1;
		subset2(n+1, k, ssum+A[n]);
	}
}
// 모든 부분집합의 합 계산.. 
void subset1(int n, int k)
{
	int i;
	int sum = 0; 
	if(n==k)
	{
		cnt2++; // 부분집합의 완성 횟수 기록.. 
		for(i=0;i<k;i++)
		{
			if(L[i]==1)
				sum += A[i];
		}
		if(sum==S)
			cnt++;
		
	}
	else
	{
		L[n] = 0;
		subset1(n+1, k);
		L[n] = 1;
		subset1(n+1, k);
	}
}


void subset(int n, int k)
{
	int i;
	if(n==k)
	{
		for(i=0;i<k;i++)
		{
			if(L[i]==1)
				printf("%d ", A[i]);
		}
		printf("\n");
	}
	else
	{
		L[n] = 0;
		subset(n+1, k);
		L[n] = 1;
		subset(n+1, k);
	}
}
