#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define Q_SIZE 100


struct Frd {
	int v;
	int c;
};
int Map[51][51];
int visited[51];
Frd queue[Q_SIZE];
int front = 0, rear = 0;
int n;
int Cnt;
vector<int> Vec;

void init() {
	for (int i = 0; i < n; i++)
		visited[i] = 0;
}

int Is_empty() {
	return rear == front;
}

void enqueue(int item, int c) {
	if ((rear + 1) % Q_SIZE == front) {
		printf("가득\n");
		return;
	}
	rear = (rear + 1) % Q_SIZE;
	queue[rear].v = item;
	queue[rear].c = c;
}
Frd dequeue() {
	front = (front + 1) % Q_SIZE;
	Frd temp;
	temp.c = queue[front].c;
	temp.v = queue[front].v;
	return temp;
}
void bfs(int v) {
	visited[v] = 1;
	enqueue(v,0);
	while (!Is_empty()) {
		Frd temp = dequeue();
		v = temp.v;
		int c = temp.c;
		if (c >= 2)continue;
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0 && Map[v][i] == 1) {
				enqueue(i, c+1);
				Cnt++;
				visited[i] = 1;
			}
		}
	}
}
void insert_grape(int start, int end) {
	Map[start][end] = 1;
	Map[end][start] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char temp;
			cin >> temp;
			if (temp == 'N')continue;
			else insert_grape(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		bfs(i);
		Vec.push_back(Cnt);
		Cnt = 0;
		init();
	}
	cout << *max_element(Vec.begin(),Vec.end()) << "\n";

	return 0;
}