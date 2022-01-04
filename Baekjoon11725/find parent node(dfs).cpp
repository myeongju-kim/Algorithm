#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int N;
int visited[MAX];
int parent[MAX];
vector<int> tree[MAX];

void dfs_tree(int v){
    visited[v] = true;
    for (int i = 0; i < tree[v].size(); i++){
        int next = tree[v][i];
        if (!visited[next]){
            parent[next] = v;
            dfs_tree(next);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> N;
    for (int i = 0; i < N - 1; i++){
        int start, end;
        cin >> start >> end;
        tree[start].push_back(end);
        tree[end].push_back(start);
    }
    dfs_tree(1);
    for (int i = 2; i <= N; i++)
        cout << parent[i] << "\n";
    return 0;

}