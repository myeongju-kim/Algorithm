#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1000001];

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int w, a, b;
		scanf("%d %d %d", &w, &a, &b);
		int t1 = find(a);
		int t2 = find(b);
		if (w == 0) parent[t2] = t1;
		else {
			if (t1 == t2) printf("YES\n");
			else printf("NO\n");
		}
	}

}
유니온 파인드 : 같은 부모인지 검사할 때 ㅈㄴ 유용함 (같은 소속인지)
다익스트라는 int cost = -que.front().first 이게 효율 더 좋음 (-dist[next])