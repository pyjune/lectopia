#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 1000000이하의 두 정 수 사이 소수의 합 구하기
int P[1000001] ; // 2는 소수
int isPrime(int n);

int main(void)
{

	int i,j;
	int tcase, T;
	long long sum, sum2;
	int a, b;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (tcase = 1; tcase <= T; tcase++)
	{
		scanf("%d %d", &a, &b);
		for (i = 2; i <= 1000000; i++)
		{
			P[i] = i;
		}
		for (i = 2; i < 1000000; i++)
		{
			for (j = 2; j <= 1000000; j++)
			{
				if ((P[i] != 0) && (i*j<=1000000))
					P[i*j] = 0;
				else
					break;
			}
		}
		sum = 0;
		for (i = a + 1; i < b; i++)
		{
			//if (P[i] != 0)
				sum += (long long)P[i];
		}
		//sum2 = 0;
		//for (i = a + 1; i < b; i++)
		//{
		//	if (isPrime(i))
		//		sum2 += (long long)i;
		//}
		printf("#%d %lld %lld\n", tcase, sum); //, sum2);
	}

}

int isPrime(int n)
{
	int i;
	if (n == 2)
		return 1;
	else if (n % 2 == 0)
		return 0;
	else
	{
		for (i = 3; i*i <= n; i++)
		{
			if (n%i == 0)
				return 0;
		}
		return 1;
	}
}