#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HEAP_SIZE 1000001
#define MAX 1000001

typedef struct inf {
	int weight;
	int price;
}inf;

int heap_count = 0;
int bag[MAX];
inf heap[HEAP_SIZE];
inf item[MAX];
inf a[MAX];
void swap(inf* a, inf* b) {
	inf tmp = *a; *a = *b; *b = tmp;
}

void init() {
	heap_count = 0;
}

int size() {
	return heap_count;
}
void push(inf data) {
	heap[++heap_count] = data;
	int child = heap_count;
	int parent = child / 2;
	while (child > 1 && heap[parent].price < heap[child].price) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

inf pop() {
	inf result = heap[1];
	swap(&heap[1], &heap[heap_count]);
	heap_count--;
	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= heap_count) {
		child = (heap[child].price > heap[child + 1].price) ? child : child + 1;
	}
	while (child <= heap_count && heap[parent].price < heap[child].price) {
		swap(&heap[parent], &heap[child]);
		parent = child;
		child = child * 2;
		if (child + 1 <= heap_count) {
			child = (heap[child].price > heap[child + 1].price) ? child : child + 1;
		}
	}
	return result;
}

​
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &item[i].weight, &item[i].price);
	for (int i = 0; i < k; i++)
		scanf("%d", &bag[i]);
	for (int i = 0; i < n; i++) {
		push(item[i]);
	}
	for (int i = 0; i < n; i++)
		a[i] = pop();

	int index = 0;
	int sum = 0;
	int v = 0;
	while (1) {
		if (v >= n) {
			v = 0;
			index++;
		}
		if (index == n) break;
		if (bag[index] >= a[v].weight) {
			index++;
			sum += a[v].price;
			a[v].weight = 100000001;
			v = 0;
		}
		else v++;

	}
	printf("%d",sum);
	return 0;
}