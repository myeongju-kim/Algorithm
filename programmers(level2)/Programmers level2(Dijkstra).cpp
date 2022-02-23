#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 999999
#define MAX 5000
int solution(int N, vector<vector<int> > road, int K) {
    int answer=0;
    vector<pair<int, int> > arr[MAX];
    for (int i = 0; i < road.size(); i++) {
        int from=road[i][0], to = road[i][1], val = road[i][2];
        arr[from].push_back({ to,val });
        arr[to].push_back({ from,val });
    }
    int V = N;
    int start = 1;
    int dist[MAX];
    fill(dist, dist + V + 1, INF);
    priority_queue<pair<int, int>> qu;
    qu.push({ 0,start });
    dist[start] = 0;
    while (!qu.empty()) {
        int cost = -qu.top().first;
        int here = qu.top().second;
        qu.pop();
        for (int i = 0; i < arr[here].size(); i++) {
            int next = arr[here][i].first;
            int nextcost = arr[here][i].second;
            if (dist[next] > cost + nextcost) {
                dist[next] = cost + nextcost;
                qu.push({ -dist[next], next });
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if(dist[i]<=K) answer++;
    }

    return answer;
}
