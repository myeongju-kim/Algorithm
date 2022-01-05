#include <stdio.h>

#define TRUE	1
#define FALSE	0
#define NODES	1000		/* 노드의 수 */
#define INF 	987654321	/* 무한 값(연결이 없는 경우) */
int distance[NODES];/* 시작노드로부터의 최단경로 거리 */
int found[NODES];		/* 방문한 노드 표시 */
int cost[NODES][NODES];

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INF;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void shortest_path(int start, int n)
{
	int i, u, w;
	for (i = 0; i < n; i++){
		distance[i] = cost[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;    /* 시작노드 방문 표시 */
	distance[start] = 0;
	for (i = 0; i < n; i++) {
		u = choose(distance, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++)
			if (!found[w]) {
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
				}
			}
	}
}

int main() {
	int n, e;
	int start,end;
	scanf("%d %d", &n, &e);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cost[i][j] = -1;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (cost[a - 1][b - 1] != -1 && cost[a - 1][b - 1] < c) continue;
		cost[a - 1][b - 1] = c;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && cost[i][j] == -1)
				cost[i][j] = INF;
		}
	}
	scanf("%d %d", &start, &end);
	shortest_path(start-1, n);
	printf("%d\n", distance[end - 1]);
	return 0;
}