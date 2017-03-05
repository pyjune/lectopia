#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int tc, T;
	int N;
	int i,j;
	int arr[10];
	int tmp;
	
	freopen("Text.txt","r", stdin);
	scanf("%d", &T);
	for(tc = 1; tc<=T; tc++)
	{
		scanf("%d", &N);
		
		printf("#%d ", tc);
		
		for(i=0;i<N;i++)
		{
			scanf("%1x", &tmp);
			for(j=3;j>=0;j--)
			{
				printf("%d", (tmp&(1<<j))?1:0);
			}	
		}
		printf("\n");
		/*
		for(i=0;i<N;i++)
		{
			scanf("%1x", &arr[i]);	
		}
		printf("#%d ", tc);
		
		for(i=0;i<N;i++)
		{
			for(j=3;j>=0;j--)
			{
				printf("%d", (arr[i]&(1<<j))?1:0);
			}
		}
		printf("\n");
		*/
	}
	
	
	return 0;
}


