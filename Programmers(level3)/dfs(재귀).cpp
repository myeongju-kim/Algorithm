#include <iostream>
#include <vector>
using namespace std;

string b = "hhh";
vector<string> words{ "hhh","hht" };
int Min = 99999;
int check(int s, string a) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != words[s][i])cnt++;
    }
    if (cnt == 1)return 1;
    else return 0;
}
void dfs(int s, int cnt, string begin, vector<int> visited) {
    if (s > words.size())return;
    if (begin == b) {
        if (Min > cnt)Min = cnt;
        return;
    }
    for (int i = 0; i < words.size(); i++) {
        if (check(i, begin) && !visited[i]) {
            visited[i] = true;
            dfs(i+1, cnt + 1, words[i], visited);
        }
    }
}
int main() {
    vector<int> visited(6,0);
    if (find(words.begin(), words.end(), b) != words.end()) {
        dfs(0, 0, "hit",visited);
        if (Min == 99999)cout << "0\n";
        else cout << Min << "\n";
    }
    else cout << "0\n";

    return 0;
}