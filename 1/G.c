#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int arr[100][100];

int main(int argc, char *argv[]) {
	
	int tc, T;
	int l, i, j;
	int N, row, col;
	int c; 
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc = 1; tc<=T; tc++)
	{
		scanf("%d %d %d", &N, &row, &col);
		c = 1;
		for(l=1;l<=N-1;l++)
		{
			for(i=0;i<N-l;i++)
			{
				j=i+l;
				arr[i][j] = c++;
			}
		}
		printf("#%d %d\n", tc, arr[row][col]);
	}
	
	
	return 0;
}





