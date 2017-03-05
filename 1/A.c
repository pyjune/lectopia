#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int A[1000];

int main(int argc, char *argv[]) {
	int tc, T;
	int N;
	int i;
	int minIdx, maxIdx;
	// 파일의 내용을 stdin으로 보냄.. 
	freopen("Text.txt", "r", stdin);
	// stdin의 내용을 읽음.. 
	scanf("%d", &T);	
	for(tc = 1;tc <= T;tc++)
	{
		minIdx = 0;
		maxIdx = 0;
		scanf("%d", &N);
		for(i=0;i<N;i++)
		{
			scanf("%d", &A[i]);
			if(A[minIdx]>A[i])
				minIdx = i;
			if(A[maxIdx]<A[i])
				maxIdx = i;
		}
		/*
		for(i=1;i<N;i++)
		{
			if(A[minIdx]>A[i])
				minIdx = i;
		}*/
		printf("#%d %d\n", tc, A[maxIdx]-A[minIdx]);
			
	}
	
	
	return 0;
}
