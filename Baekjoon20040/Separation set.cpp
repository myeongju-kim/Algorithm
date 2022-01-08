#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

int getParent(int parent[], int node) {
	if (parent[node] == node) {
		return node;
	}
	return getParent(parent, parent[node]);
}

int unionParent(int parent[], int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);
	if (x < y) {
		parent[y] = x;
		return x;
	}
	else {
		parent[x] = y;
		return y;
	}
}

int findParent(int parent[], int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);
	if (x == y) { 
		return 1;
	}
	else { 
		return 0;
	}
}

class Edge {
public:
	int node[2]; 
	Edge(int x, int y) {
		this->node[0] = x;
		this->node[1] = y;
	}
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; 
	int m; 
	cin >> n >> m;
	vector<Edge> v;
	int* parent = new int[n];
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back(Edge(s, e));
	}
	for (int i = 0; i < n; i++) parent[i] = i;
	int flag = 0;
	for (int i = 0; i < v.size(); i++) {
		if (findParent(parent, v[i].node[0], v[i].node[1])) {
			flag = i + 1;
			break;
		}
		unionParent(parent, v[i].node[0], v[i].node[1]);
	}
	cout << flag << "\n";
	delete[] parent;
	return 0;
}

