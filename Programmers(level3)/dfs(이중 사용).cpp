#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<string>> tic{ {"ICN","BOO"},{"ICN", "COO"},{"COO", "DOO"},{"DOO","COO"},{"BOO","DOO"}, {"DOO","BOO"}, {"BOO","ICN"}, {"COO","BOO"} };
set<pair<string, int>> s;
vector<string> ans;
vector<int> visited(10001,0);
int sign=0;
int check(vector<int> visited) {
    for (int i = 0; i < tic.size(); i++) {
        if (!visited[i]) return 0;
    }
    return 1;
}
void travel(string start, vector<int>& visited, int cnt) {
    if (check(visited)) {
        sign = 1;
        return;
    }
    for (int i = 0; i < tic.size(); i++) {
        if (start == tic[i][0] && !visited[i]) {
            visited[i] = true;
            travel(tic[i][1], visited, cnt + 1);
        }
    }
}
void dfs(string start) {
    ans.push_back(start);
    for (int i = 0; i < tic.size(); i++) {
        if (tic[i][0] == start && !visited[i]) {
            s.insert({ tic[i][1],i });
        }
    }
    if (s.empty())return;
    string temp;
    if (s.size() == 1) {
        temp = s.begin()->first;
        visited[s.begin()->second] = true;
    }
    else {
        for (auto iter=s.begin(); iter!=s.end(); iter++) {
            cout << iter->first << " ";
            vector<int> t(10001);
            copy(visited.begin(), visited.end(), t.begin());
            travel(iter->first, t, 0);
            if (sign == 1) {
                sign = 0;
                temp = iter->first;
                visited[iter->second] = true;
                break;
            }
        }
        cout << "\n---------------------------\n";
    }
    s.clear();
    dfs(temp);
}
int main() {
    dfs("ICN");
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}