#include <stdio.h>

int adj[11][11];
int v[11];

void bfs(int n, int k);

int main(void)
{
	int V, E;
	
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		adj[n2][n1] = 1;
	}
	bfs(1, V);

	int sum = 0; 
	for (int i = 1; i <= V; i++)
	{
		sum += v[i]; // v가 가진 거리 정보를 누적
	}
	sum -= V; // v에 1씩 더해져 있으므로..
	printf("%d\n", sum);
}

void bfs(int n, int k)
{
	int Q[11];
	int front = -1;
	int rear = -1;
	// 초기화
	v[n] = 1;
	Q[++rear] = n;
	// 반복
	while (front != rear) // Q가 비어있지 않으면
	{
		n = Q[++front]; // deQ()
		for (int i = 1; i <= k; i++) // 모든 노드 i에 대해
		{
			if ((adj[n][i] == 1) && (v[i] == 0)) // i가 n에 인접이고 미방문이면
			{
				Q[++rear] = i; // enQ(i);
				v[i] = v[n] + 1; // i는 n으로부터 인접으로 처리됨을 기록
			}
		}
	}
}
