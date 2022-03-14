#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 1011
#define INF 987654321
int V, E, X;
vector<pair<int, int>> arr[MAX];
vector<int> ans1;
vector<int> ans2;
void dijkstra(int s, int flag) {
	int dist[MAX];
	for (int j = 1; j <= V; j++) dist[j] = INF;
	priority_queue<pair<int, int>> que;
	que.push({ 0,s });
	dist[s] = 0;
	while (!que.empty()) {
		int cost = que.top().first;
		int here = que.top().second;
		que.pop();
		for (int j = 0; j < arr[here].size(); j++) {
			int next = arr[here][j].first;
			int nextcost = arr[here][j].second;
			if (dist[next] >= cost + nextcost) {
				dist[next] = cost + nextcost;
				que.push({ dist[next],next });
			}
		}
	}
	if (flag == 0) {
		for (int i = 1; i <= V; i++)
			ans1.push_back(dist[i]);
	}
	else {
		for (int i = 1; i <= V; i++)
			ans2.push_back(dist[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E >> X;
	vector<vector<int>> temp;
	for (int i = 0; i < E; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		temp.push_back({ from,to,val });
		arr[from].push_back({ to,val });
	}
	dijkstra(X,0);
	for (int i = 1; i <= V; i++) arr[i].clear();
	for (int i = 0; i < E; i++) {
		int from = temp[i][0], to = temp[i][1], val = temp[i][2];
		arr[to].push_back({ from,val });
	}
	dijkstra(X, 1);
	int max = 0;
	for (int i = 0; i < ans1.size(); i++) {
		int sum = ans1[i] + ans2[i];
		if (max < sum) max = sum;
	}
	cout << max;
	
}