#include <stdio.h>
#define VERTEX 101
#define Q_SIZE 5001

int queue[Q_SIZE];
int front = 0, rear = 0;
int Count = 0;
int is_empty() {
	return rear == front;
}
void enqueue(int item) {
	if ((rear + 1) % Q_SIZE == front) {
		printf("가득\n");
		return;
	}
	rear = (rear + 1) % Q_SIZE;
	queue[rear] = item;
}
int dequeue() {
	if (is_empty()) {
		printf("빈공간\n");
		return 0;
	}
	front = (front + 1) % Q_SIZE;
	return queue[front];
}
void Insert_edge(int mat[VERTEX][VERTEX], int start, int end) {
	mat[start][end] = 1;
	mat[end][start] = 1;
}
void bfs_mat(int mat[VERTEX][VERTEX], int v, int bfs_visited[VERTEX], int bfs_count[VERTEX], int n) {
	int count = 1;
	bfs_visited[v] = 1;
	//printf("%d -> ", v);
	enqueue(v);
	while (!is_empty()) {
		v = dequeue();
		count = bfs_count[v] + 1;
		for (int i = 0; i < n; i++) {
			if (bfs_visited[i] == 0 && mat[v][i] == 1) {
				enqueue(i);
				bfs_visited[i] = 1;
				//printf("%d -> ", i);
				bfs_count[i] = count;
			}
		}
	}
}

int main() {
	int mat[VERTEX][VERTEX] = { 0 };
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		Insert_edge(mat, a - 1, b - 1);
	}
	int min;
	int index;
	for (int i = 0; i < n; i++) {
		int bfs_visited[VERTEX] = { 0 };
		int bfs_count[VERTEX] = { 0 };
		int sum = 0;
		bfs_mat(mat, i, bfs_visited, bfs_count, n);
		for (int j = 0; j < n; j++)
			sum += bfs_count[j];
		if (i == 0) {
			min = sum;
			index = 0;
		}
		else{
			if (min > sum) {
				index = i;
				min = sum;
			}
		}
	}
	printf("%d", index+1);
	return 0;
}