#include <stdio.h>


int main(void)
{
	int a[100][100];
	int tcase, T;
	int i, N;
	int R, C, r, c;
	int k;

	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (tcase = 1; tcase <= T; tcase++)
	{
		scanf("%d %d %d", &N, &R, &C);
		k = 1;
		for (i = 0; i <= N / 2; i++)
		{
			r = i;
			for (c = i; c < N - i - 1; c++) //  ���� �� 
				a[r][c] = k++;
			for (r = i; r < N - i - 1; r++) // ������ ����
				a[r][c] = k++;
			for (c = N - i - 1; c > i; c--) // �Ʒ��� ��
				a[r][c] = k++;
			for (r = N - i - 1; r > i; r--) // ���� ����
				a[r][c] = k++;

		}
		a[r][c] = k; // �߽ɺδ� ���� ó���մϴ�.
		printf("#%d %d\n", tcase, a[R][C]);
	}
}