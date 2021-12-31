#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10
using namespace std;

vector<int> v;
int n, m;
int arr[MAX] = { 0 };
int visited[MAX] = { 0 };
void dfs(int cnt, int start){
    if(cnt==m){   
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
         }
            cout << "\n";
        return;
    }
    int temp = 0;
    for (int i = start; i <= n; i++){
        if (!visited[i] && v[i - 1] != temp) {
            visited[i] = true;
            arr[cnt] = v[i - 1];
            temp = arr[cnt];
            dfs(cnt + 1, 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    dfs(0, 1);
    return 0;
}