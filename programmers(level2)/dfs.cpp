#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int visited[201];
vector<int> check;
void dfs(int v, vector<vector<int>> computers){
    visited[v]=true;
    check.push_back(v);
    for(int i=0; i<computers.size(); i++)
        if(!visited[i] && computers[v][i])
            dfs(i, computers);
}

int solution(int n, vector<vector<int>> computers){
    check.push_back(-1);
    int answer = 0;
    for(int i=0; i<computers.size(); i++){
        if(find(check.begin(), check.end(), i)==check.end()){
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}